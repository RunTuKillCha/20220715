#include "WinApp.h"
#include <typeinfo>
#include "Config.h"

WND_PARAM(WIN_WIDTH, WIN_HIGHT, WIN_XPIANYI, WIN_YPIANYI, L"植物人大战僵尸")

CREAIE_OBJECT(WinApp)

WinApp::WinApp(){
	//m_lstent.push_back(new CPlayer);
}
WinApp::~WinApp(){}

void WinApp::On_Init()
{
	m_Back.InitBack();
	m_player.Init();
	ui.initUI();
	m_listTree.InitAllTree();
	SteTimer();
}

void WinApp::On_Paint()
{
	m_Back.ShowBack();
	m_listTree.ShowAllTree();
	m_listFoe.ShowAllFoe();
	m_listbullet.ShowAllBullet();
	m_player.Show();
	ui.showUI(m_player.m_HP);
	
}

void WinApp::On_Close(){}

void WinApp::AddMsgMap()
{
	ADD_MSG_MAP(WM_TIMER, EX_WINDOW, WinApp)

	ADD_MSG_MAP(WM_KEYDOWN, EX_KEY, WinApp)

	ADD_MSG_MAP(WM_LBUTTONDOWN, EX_MOUSE, WinApp)


	CGameFrame::AddMsgMap();
}

void WinApp::On_WM_LBUTTONDOWN(int x, int y){
	//m_player.
	m_listbullet.m_listbullet.push_back((CBullet*)m_player.Fire(x, y));
}

void WinApp::On_WM_KEYDOWN(int key)
{
	//if (key == 87 || key == 83 || key == 65 || key == 68) {
	//	m_player.m_Sequenceframes = 0;
	//	m_player.m_curAction = 1;
	//	m_player.Move(key, OLAYER_STEP);
	//}
	//else { 
	//	m_player.m_Sequenceframes = 0;
	//	m_player.m_curAction = 0; 
	//}

}

void WinApp::On_WM_TIMER(WPARAM w, LPARAM l)
{
	switch (w) {
	case GAME_DATA_TIMERID:/*游戏数据更新*/ {
		m_Back.MoveBack(m_player);
		m_listTree.MoveAllTree(m_Back);
		m_listFoe.MoveAllFoe(m_Back.m_x, m_Back.m_y);
		break;
	}
	case USER_OPERATE_TIMERID:/*用户操作数据*/ {
		//MOUSEMSG msg;//= GetMouseMsg();
		//if ((msg = GetMouseMsg()).uMsg == WM_MOUSEMOVE) {
		//	cout << msg.x << msg.y << endl;
		//}
		if (GetAsyncKeyState(87)) {
			m_player.m_curAction = 1;
			m_player.Move(87, OLAYER_STEP);
		}
		if (GetAsyncKeyState(83)) {
			m_player.m_curAction = 1;
			m_player.Move(83, OLAYER_STEP);
		}
		if (GetAsyncKeyState(65)) {
			m_player.m_lr = 1;
			m_player.m_curAction = 1;
			m_player.Move(65, OLAYER_STEP);
		}
		if (GetAsyncKeyState(68)) {
			m_player.m_lr = 0;
			m_player.m_curAction = 1;
			m_player.Move(68, OLAYER_STEP);
		} 
		if (!(GetAsyncKeyState(87) || GetAsyncKeyState(83) || GetAsyncKeyState(65) || GetAsyncKeyState(68))) {
			m_player.m_curAction = 0;
		}
		break;
	}
	case PALYER_SHOW_TIMERID:/*人物动作更新*/ {
		m_player.m_Sequenceframes++;
		IMAGE* temimg = m_player.m_Frames[m_player.m_curAction * 2 + m_player.m_lr]
			[m_player.m_Sequenceframes];
		if (temimg == nullptr)
			m_player.m_Sequenceframes = 0;
		break;
	}
	case BULLET_MOVE_TIMERID:/*子弹定时移动*/ {
		m_listbullet.MoveAllBullet(m_Back.m_x, m_Back.m_y);
		break;
	}
	case CREATE_FOE_TIMERID:/*随机产生敌人*/ {
		CFoe* pFoe = new CFoe;
		pFoe->Init(m_Back.m_x, m_Back.m_y);
		m_listFoe.m_listfoe.push_back(pFoe);
		break;
	}
	case FOE_SHOW_TIMERID:/*敌人动作*/ {
		list<CFoe*>::iterator ite = m_listFoe.m_listfoe.begin();
		while (ite != m_listFoe.m_listfoe.end()) {
			(*ite)->m_Sequenceframes++;
			IMAGE* temimg = m_listFoe.m_Frames[(*ite)->m_curAction * 2 + (*ite)->m_lr]
				[(*ite)->m_Sequenceframes];
			if ((*ite)->isDie && (*ite)->once) {
				(*ite)->m_curAction = 1;
                (*ite)->m_Sequenceframes = 0;
				(*ite)->once = false;
			}
			if (temimg == nullptr)
				if ((*ite)->m_curAction == 1) {
					delete (*ite);
					(*ite) = nullptr;
					ite = m_listFoe.m_listfoe.erase(ite);
					continue;
				}
				else (*ite)->m_Sequenceframes = 0;

			ite++;
		}
		
		break;
	}
	case CHECK_HIT_TIMERID:/*碰撞检测*/ {
		bool isBoom = false;
		list<CFoe*>::iterator iteFoe = m_listFoe.m_listfoe.begin();
		while (iteFoe != m_listFoe.m_listfoe.end()) {
			list<CBullet*>::iterator iteBull = m_listbullet.m_listbullet.begin();
			while (iteBull != m_listbullet.m_listbullet.end()) {
				if ((*iteFoe)->lsHitBullet(*iteBull)) {
					delete (*iteBull);
					(*iteBull) = nullptr;
					iteBull = m_listbullet.m_listbullet.erase(iteBull);

					if (((*iteFoe)->m_HP -= BULLET_HIT) <= 0) {
						(*iteFoe)->isDie = true;
						isBoom = true;
					}
					continue;
				}
				iteBull++;
			}
			if (isBoom) isBoom = false;
			else iteFoe++;
		}
		break;
	}
	case FOE_DIE_TIMERID:/*扣血*/ {
		list<CFoe*>::iterator itefoes = m_listFoe.m_listfoe.begin();
		while (itefoes != m_listFoe.m_listfoe.end()) {
			if ((*itefoes)->lsHitPlayer()) {
				m_player.m_HP -= 5;
				//cout << "hp--" << endl;
			}
			itefoes++;
		}
		if (m_player.m_HP <= 0) {
			KillTime();
			MessageBox(m_hwnd, L"You Die!", L"提示", MB_OK);
			PostMessage(m_hwnd, WM_CLOSE, 0, 0);
			return;
		}
		break;
	}

	}
}

void WinApp::SteTimer()
{
	SetTimer(m_hwnd, GAME_DATA_TIMERID, GAME_DATA_INTERVAL, nullptr);
	SetTimer(m_hwnd, USER_OPERATE_TIMERID, USER_OPERATE_INTERVAL, nullptr);
	SetTimer(m_hwnd, PALYER_SHOW_TIMERID, PALYER_SHOW_INTERVAL, nullptr);
	SetTimer(m_hwnd, BULLET_MOVE_TIMERID, BULLET_SMOVE_INTERVAL, nullptr);
	SetTimer(m_hwnd, CREATE_FOE_TIMERID, CREATE_FOE_INTERVAL, nullptr);
	SetTimer(m_hwnd, FOE_MOVE_TIMERID, FOE_MOVE_INTERVAL, nullptr);
	SetTimer(m_hwnd, FOE_SHOW_TIMERID, FOE_SHOW_INTERVAL, nullptr);
	SetTimer(m_hwnd, CHECK_HIT_TIMERID, CHECK_HIT_INTERVAL, nullptr);
	SetTimer(m_hwnd, FOE_DIE_TIMERID, FOE_DIE_INTERVAL, nullptr);
}

void WinApp::KillTime()
{
	KillTimer(m_hwnd, GAME_DATA_TIMERID);
	KillTimer(m_hwnd, USER_OPERATE_TIMERID);
	KillTimer(m_hwnd, PALYER_SHOW_TIMERID);
	KillTimer(m_hwnd, BULLET_MOVE_TIMERID);
	KillTimer(m_hwnd, CREATE_FOE_TIMERID);
	KillTimer(m_hwnd, FOE_MOVE_TIMERID);
	KillTimer(m_hwnd, FOE_SHOW_TIMERID);
	KillTimer(m_hwnd, CHECK_HIT_TIMERID);
	KillTimer(m_hwnd, FOE_DIE_TIMERID);
}

void WinApp::ShowUI(){
}

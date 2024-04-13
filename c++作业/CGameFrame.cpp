#include "CGameFrame.h"

CGameFrame* pGame = nullptr;

CGameFrame::CGameFrame():m_hwnd(NULL),m_isQuit(false){}
CGameFrame::~CGameFrame(){}

void CGameFrame::InitGame(int width, int height, int x, int y, const WCHAR* p)
{
	m_hwnd = initgraph(width, height);

	MoveWindow(m_hwnd, x, y, width, height, true);
	SetWindowText(m_hwnd, p);

	SetWindowLong(m_hwnd, GWL_WNDPROC, (LONG)&CGameFrame::RunGame);

	AddMsgMap();

	On_Init();
}

void CGameFrame::AddMsgMap()
{
	/*m_msgMap[WM_LBUTTONDOWN].MsgType = EX_MOUSE;
	m_msgMap[WM_LBUTTONDOWN].p_fun_EX_MOUSE = &CGameFrame::On_WM_LBUTTONDOWN;

	m_msgMap[WM_KEYDOWN].MsgType = EX_KEY;
	m_msgMap[WM_KEYDOWN].p_fun_EX_KEY = &CGameFrame::On_WM_KEYDOWN;

	m_msgMap[WM_CLOSE].MsgType = EX_WINDOW;
	m_msgMap[WM_CLOSE].p_fun_EX_WINDOW = &CGameFrame::CloseGame;*/

	
	ADD_MSG_MAP(WM_CLOSE, EX_WINDOW,CGameFrame);

}

void CGameFrame::PaintGame()
{
	BeginBatchDraw();
	cleardevice();

	On_Paint();


	EndBatchDraw();

}

LRESULT CALLBACK CGameFrame::RunGame(HWND hWindow,UINT uMsg,WPARAM wPrarm,LPARAM lparam)
{
	//if (uMsg == WM_LBUTTONDOWN)
	//{
	//	pGame->On_WM_LBUTTONDOWN(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
	//}
	//if (uMsg == WM_KEYDOWN)
	//{
	//	pGame->On_WM_LBUTTONDOWN(wPrarm);
	//}
	//if (uMsg == WM_CLOSE)
	//{
	//	pGame->CloseGame();
	//}
	
	if(pGame->m_msgMap.count(uMsg))
	{
		switch (pGame->m_msgMap[uMsg].MsgType)
		{
		case EX_MOUSE:
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_MOUSE)(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
			break;
		case EX_KEY:
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_KEY)(wPrarm);
			break;
		case EX_WINDOW:
			(pGame->*pGame->m_msgMap[uMsg].p_fun_EX_WINDOW)(wPrarm, lparam);
			break;

		}
		pGame->PaintGame();
	}
	return DefWindowProc(hWindow, uMsg, wPrarm, lparam);
}

void CGameFrame::On_WM_CLOSE(WPARAM, LPARAM)
{
	On_Close();
	closegraph();
	pGame->m_isQuit = true;
}


extern int width;
extern int height;
extern int pos_x;
extern int pos_y;
extern const WCHAR* pTitle;


CGameFrame* CreateObject();

int main()
{
	/*IMAGE img1;
	loadimage(&img1, L"1.png");
	putimage(0, 0, &img1);*/
	pGame = CreateObject();
	pGame->InitGame(width, height, pos_x, pos_y, pTitle);
	pGame->PaintGame();


	while(!pGame->m_isQuit)
	Sleep(2000);
	


	delete pGame;
	pGame = nullptr;


	return 0;
}

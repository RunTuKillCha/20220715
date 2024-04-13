#include "CPlayer.h"
#include <cwchar>
#include <typeinfo>
#include "CBullet.h"



CPlayer::CPlayer():name("HK416"),m_curAction(0),m_Sequenceframes(0),m_lr(0),m_Frames(),c_x(0),c_y(0),m_x(0),m_y(0)
{
	m_HP = 100;
	m_x = (WIN_XWEIZHI / 2) - PLAYER_XWEIZHI / 2;
	m_y = (WIN_YWEIZHI / 2) - PLAYER_YWEIZHI / 2;
	//isshow = true;
}

const wchar_t* fun(int i) {
	if (i == 0)
		return L"wait";
	if (i == 1)
		return L"move";
}

void CPlayer::Init()
{
	int i = 0;
	int f = 0;
	while (i < AUTO)
	{
		int k = 1;
		while (k >= 0)//×óÓÒ
		{
			wchar_t LR = L'R';
			if (k == 0)LR = L'L';

			for (int j = 0; j < 200; j++)
			{
				WCHAR strname[50];
				swprintf(strname, size(strname), 
					L"res/Cards/HK416/%lc/%ls/HK416_557_%ls_25_%03d.png",
					LR, fun(i), fun(i), j);
				if (Ext(strname)) {
					m_Frames[f][j] = new IMAGE;
					loadimage(m_Frames[f][j], strname);
				}
				else break;
			}
			f++;
			k--;
		}
		i++;
	}
}

void CPlayer::Show(){
	if (CUR_IMG == nullptr) m_Sequenceframes = 0;
	putimagePNG(m_x, m_y, CUR_IMG);
}

void* CPlayer::Fire(int msg_x,int msg_y)
{
	CBullet* pBull = new CBullet(msg_x, msg_y);
	pBull->InitBullet(c_x, c_y,m_lr);
	return pBull;
}

void CPlayer::Move(int direct, int step)
{
	if ( direct == 87)
	{
		c_y + step <= BACK_HIGHT /2 ? c_y += step : c_y = BACK_HIGHT / 2;
	}
	else if ( direct == 83)
	{
		c_y - step >= -(BACK_HIGHT / 2) ? c_y -= step : c_y = -(BACK_HIGHT / 2);
	}
	else if ( direct == 65)
	{
		c_x - step >= -(BACK_WIDTH / 2) ? c_x -= step : c_x = -(BACK_WIDTH / 2);
	}
	else if ( direct == 68)
	{
		c_x + step <= BACK_WIDTH / 2 ? c_x += step : c_x = BACK_WIDTH / 2;
	}
}

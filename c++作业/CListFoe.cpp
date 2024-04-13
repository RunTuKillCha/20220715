#include "CListFoe.h"

const wchar_t* funs(int i) {
	if (i == 0)
		return L"move";
	if (i == 1)
		return L"kill";
	if (i == 2)
		return L"eat";
}

CListFoe::CListFoe():m_Frames(){
	int i = 0;
	int f = 0;
	while (i < CFoe::AUTO)
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
					L"res/Cards/Zombies/%lc/%ls/%d.png",
					LR, funs(i), j);
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

CListFoe::~CListFoe()
{
	list<CFoe*>::iterator ite = m_listfoe.begin();
	while (ite != m_listfoe.end()) {
		if (*ite) {
			delete (*ite);
			(*ite) = nullptr;
		}
		++ite;
	}
	m_listfoe.clear();
}

#define CUR_ACT m_curAction*2+m_lr
#define CUR_IMG m_Frames[CUR_ACT][m_Sequenceframes]
void CListFoe::ShowAllFoe()
{
	for (CFoe* p : m_listfoe) { 
		//if (p)p->Show();
		if (m_Frames[p->m_curAction * 2 + p->m_lr][p->m_Sequenceframes] == nullptr) p->m_Sequenceframes = 0;
		putimagePNG(p->m_x - FOE_WIDTH / 2, p->m_y - FOE_HIGHT / 2, m_Frames[p->m_curAction * 2 + p->m_lr][p->m_Sequenceframes]);
	}
}

void CListFoe::MoveAllFoe(int& x, int& y)
{
	list<CFoe*>::iterator iteF = m_listfoe.begin();
	while (iteF != m_listfoe.end()) {
		if (*iteF)(*iteF)->Move(x, y);
		if ((*iteF)->m_x > PLAYER_XWEIZHI * 1.5 && (*iteF)->m_x < -PLAYER_XWEIZHI * 1.5 &&
			(*iteF)->m_y > PLAYER_YWEIZHI * 1.5 && (*iteF)->m_y < -PLAYER_YWEIZHI * 1.5) {
			delete (*iteF);
			(*iteF) = nullptr;
			iteF = m_listfoe.erase(iteF);
			continue;
		}
		iteF++;
	}
}

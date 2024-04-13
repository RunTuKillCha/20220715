#include "CListBullet.h"
#include "Config.h"

CListBullet::~CListBullet()
{
	list<CBullet*>::iterator ite = m_listbullet.begin();
	while (ite != m_listbullet.end())
	{
		if ((*ite)) {
			delete (*ite);
			(*ite) = nullptr;
		}
		ite++;
	}
	m_listbullet.clear();
}

void CListBullet::ShowAllBullet(){
	list<CBullet* > ::iterator ite = m_listbullet.begin();
	while (ite != m_listbullet.end()) {
		(*ite)->ShowBullet();
		ite++;
	}
}

void CListBullet::MoveAllBullet(int x, int y)
{
	list<CBullet* > ::iterator ite = m_listbullet.begin();
	while (ite != m_listbullet.end()) {
		if ((*ite)->m_x > 0 && (*ite)->m_x < WIN_XWEIZHI
			&& (*ite)->m_y >0 && (*ite)->m_y < WIN_YWEIZHI)
			(*ite)->MoveBullet(x, y);
		else {
			delete (*ite);
			(*ite) = nullptr;
			ite = m_listbullet.erase(ite);
			continue;
		}
		ite++;
	}
}


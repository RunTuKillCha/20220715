#pragma once
#include "CBullet.h"
#include <list>
#include "Foe.h"
using namespace std;
class CListFoe{
public:
	IMAGE* m_Frames[CFoe::AUTO * 2][40];// m_Frames[¶¯×÷][Ö¡]
	list<CFoe*> m_listfoe;
	list<CFoe*> m_listfoeOver;
public:
	CListFoe();
	~CListFoe();
	void ShowAllFoe();
	void MoveAllFoe(int &, int&);//¸úËæ±³¾°ÒÆ¶¯

};


#pragma once
#include "CBullet.h"
#include <list>
using namespace std;
class CListBullet
{
public:
	list<CBullet*> m_listbullet;

public:
	//CListBullet();
	~CListBullet();
	void ShowAllBullet();
	void MoveAllBullet(int ,int);//¸úËæ±³¾°ÒÆ¶¯
};


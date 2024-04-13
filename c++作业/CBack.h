#pragma once
#include <graphics.h>
#include "CPlayer.h"

class CBack{
public:
	int m_x, m_y;
	int c_x, c_y;
	IMAGE m_back;
public:
	CBack();
	~CBack();
	void InitBack();
	void MoveBack(CPlayer& player);
	void ShowBack();

	

};


#pragma once
#include <graphics.h>
#include "CBack.h"
#include "Config.h"

class CTree
{
public:
	int m_x, m_y;
	int c_x, c_y;

	CTree();
	void moveTree(CBack& back);
};


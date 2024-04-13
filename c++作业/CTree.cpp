#include "CTree.h"

CTree::CTree():m_x(0),m_y(0), c_x(200), c_y(300) {}

void CTree::moveTree(CBack& back){
	m_x = back.m_x - (-BACK_WIDTH / 2) + c_x;
	m_y = back.m_y - (-BACK_HIGHT / 2) + c_y;
}


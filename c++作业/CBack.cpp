#include "CBack.h"
#include "Config.h"

CBack::CBack() :m_x(-BACK_WIDTH / 2), m_y(-BACK_HIGHT / 2), c_x(0), c_y(0) {

}
CBack::~CBack() {}

void CBack::InitBack()
{
	loadimage(&m_back, L"./res/maps/map.png");
}

void CBack::ShowBack()
{
	putimage(-5120, -3200, &m_back);
}

void CBack::MoveBack(CPlayer& player)
{
	m_x = -BACK_WIDTH / 2 - player.c_x;
	m_y = -BACK_HIGHT / 2 + player.c_y ;
}

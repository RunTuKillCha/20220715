#include "Foe.h"
#include "Config.h"


random_device CFoe::rd;

CFoe::CFoe() :m_HP(20),m_curAction(0), m_Sequenceframes(0), m_lr(0),
c_x(0), c_y(0), m_x(0), m_y(0),isDie(false),once(true){}

CFoe::~CFoe(){}


void CFoe::Init(int x,int y){

	int r = rand() % 4;
	float x1 = rd() % (int)WIN_XWEIZHI;
	float y1 = rd() % (int)WIN_YWEIZHI;
	if ( r== 0) {
		m_x =x1;
		m_y = 0;
	}
	else if (r == 1) {
		m_x = x1;
		m_y = WIN_YWEIZHI;
	}
	else if (r == 2) {
		m_x = 0;
		m_y = y1;
	}
	else if (r == 3) {
		m_x = WIN_XWEIZHI;
		m_y = y1;
	}
	c_x = x;c_y = y;
	RMove();
}

void CFoe::RMove() {
	k = ((float)m_y - (float)WIN_YWEIZHI / 2.0) / ((float)m_x - (float)WIN_XWEIZHI / 2.0);
	float alna = atan(k) * 180.0 / PI;
	float fy = fabs(sin(alna * PI / 180.0));
	float fx = fabs(cos(alna * PI / 180.0));
	m_ry = fy * FOE_MOVE_STEP;
	m_rx = fx * FOE_MOVE_STEP;
	if (m_x >= WIN_XWEIZHI / 2.0 && m_x < WIN_XWEIZHI && m_y <= WIN_YWEIZHI / 2.0 && m_y >0) m_rx = -m_rx;
	else if (m_x < WIN_XWEIZHI / 2.0 && m_x > 0 && m_y < WIN_YWEIZHI / 2.0 && m_y >0);
	else if (m_x <= WIN_XWEIZHI / 2.0 && m_x > 0 && m_y >= WIN_YWEIZHI / 2.0 && m_y < WIN_YWEIZHI) m_ry = -m_ry;
	else if (m_x > WIN_XWEIZHI / 2.0 && m_x < WIN_XWEIZHI && m_y > WIN_YWEIZHI / 2.0 && m_y < WIN_YWEIZHI) {
		m_rx = -m_rx;
		m_ry = -m_ry;
	}
}

bool CFoe::lsHitPlayer()
{
	if (isDie) return false;

	if (m_x > WIN_XWEIZHI /2 - PLAYER_WIDTH /2 && m_x < WIN_XWEIZHI / 2 + PLAYER_WIDTH / 2 &&
		m_y > WIN_YWEIZHI / 2 - PLAYER_HIGHT / 2 && m_y < WIN_YWEIZHI / 2 + PLAYER_HIGHT / 2) {
		m_curAction = 2;
		return true;
	}
	m_curAction = 0;
	return false;
}

bool CFoe::lsHitBullet(CBullet* pBull)
{
	int x = pBull->m_x + BULLET_WIDTH / 2;
	int y = pBull->m_y + BULLET_HEIGHT / 2;

	if (x > m_x - FOE_WIDTH/2 && x < m_x + FOE_WIDTH / 2 &&
		y > m_y - FOE_HIGHT / 2 && y < m_y + FOE_HIGHT / 2) {
		return true;
	}

	return false;
}

void CFoe::Move(int& x, int& y){
	

	m_x += -(c_x - x);
	m_y += -(c_y - y);
	c_x = x;c_y = y;
	if (isDie) return;
	RMove();
	m_x += m_rx;
	m_y += m_ry;
	if (m_rx < 0 && m_curAction != 2) m_lr = 1;
	else m_lr = 0;
}
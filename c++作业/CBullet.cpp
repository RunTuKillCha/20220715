#include "CBullet.h"
#include "Config.h"
#include  <math.h>
CBullet::CBullet(int x,int y):m_x(0),m_y(0),c_x(0),c_y(0),m_lr(0),m_zx(x),m_zy(y),k(0),m_rx(0),m_ry(0),fx(0),fy(0),xx(1) {
}

void CBullet::InitBullet(int c_x,int c_y ,int lr){
	loadimage(&m_bullet, L"./res/gunner.jpg");
	int x = 40;
	m_lr = lr;
	if (lr == 1)x = -x - 5;

	CBullet::c_x = c_x;
	CBullet::c_y = c_y;

	m_x = WIN_XWEIZHI / 2;
	m_y = WIN_YWEIZHI / 2;

	//-------------------------------------------------------
	//将；落点视口坐标转换成世界坐标计算


	//m_zx = m_zx - WIN_XWEIZHI / 2;
	//m_zy =m_zy - WIN_YWEIZHI / 2;
	//------------------------------------------------
	RMoveBullet();
}

void CBullet::ShowBullet(){
	putimage(m_x, m_y, BULLET_WIDTH, BULLET_HEIGHT,
		&m_bullet, BULLET_WIDTH, 0, SRCPAINT);
	putimage(m_x, m_y, BULLET_WIDTH, BULLET_HEIGHT,
		&m_bullet, 0, 0, SRCAND);
}

void CBullet::MoveBullet(int x/*m_Back.m_x*/, int y/*m_Back.m_y*/) {
	int k = 40;
	if (m_lr == 1)k = -x - 5;
	int xred = 40;
	if (m_lr == 1)xred = -xred - 5;
	//x - (-BACK_WIDTH / 2) = ^_背景偏移量(人物移动的量） + (-c_x + WIN_XWEIZHI / 2) = 子弹的构造坐标->(视口坐标)
	// 就是将子弹的世界坐标转换成视口坐标再加上背景在这之后的偏移
	m_x +=/* -temx*/ +m_rx + 0.5;
	m_y += /*-temy*/ + m_ry + 0.6;
	int a;
}

void CBullet::RMoveBullet(){
	//  y=kx+b
	// k = (Y1-Y2)/ (X1-X2)
	// k = (m_zy - c_y)/(m_zx - c_x)
	//------------------------------------------
	k =((float)m_zy - (float)WIN_YWEIZHI / 2.0) / ((float)m_zx - (float)WIN_XWEIZHI / 2.0);
	if (m_zx < WIN_XWEIZHI / 2) {
		if (m_zy < WIN_YWEIZHI / 2) xx = 2;
		else xx = 3;
	}
	else 	if (m_zy > WIN_YWEIZHI / 2) xx = 4;
	float alna = atan(k) * 180.0 / PI;
	fy = fabs(sin(alna * PI / 180.0));
	fx = fabs(cos(alna * PI / 180.0));
	m_ry = fy * BULLET_MOVE_STEP;
	m_rx = fx * BULLET_MOVE_STEP;
	if (xx == 1) m_ry = -m_ry;
	else if (xx == 2) {m_rx = -m_rx; m_ry = -m_ry;}
	else if (xx == 3) m_rx = -m_rx;
}


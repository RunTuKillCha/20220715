#pragma once
#include <graphics.h>
//#include "CBack.h"


class CBullet{
public:
	IMAGE m_bullet;
	float m_x, m_y;
	float c_x, c_y;
	float m_zx, m_zy;//Âäµã
	float m_rx, m_ry;//×Óµ¯Æ«ÒÆ
	int m_lr;
	float k, xx;
	float fy, fx;
public:
	CBullet(int ,int);
	void InitBullet(int c_x, int c_y,int lr);
	void ShowBullet();
	void MoveBullet(int, int);
	void RMoveBullet();
};


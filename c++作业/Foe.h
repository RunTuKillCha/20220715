#pragma once
#include <graphics.h>
#include "CBack.h"
#include "CBullet.h"
#include <random>
class CFoe
{
public:
	float m_x, m_y;//这是视口坐标
	float c_x, c_y;//这是世界坐标
	int m_HP;
	int m_lr;//0为右1为左
	int m_curAction;//当前动作 
	int m_Sequenceframes;//当前帧数
	enum { MOVE, KILL , EAT , AUTO };//总动作数
	float k;
	float m_rx, m_ry;
	float m_bx, m_by;
	bool isDie, once;
	static random_device rd;

public:
	CFoe();
	~CFoe();
	void Init(int x, int y);
	void Move(int&, int&);
	void RMove();
	bool lsHitPlayer();
	bool lsHitBullet(CBullet* pBull);
};


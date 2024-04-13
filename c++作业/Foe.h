#pragma once
#include <graphics.h>
#include "CBack.h"
#include "CBullet.h"
#include <random>
class CFoe
{
public:
	float m_x, m_y;//�����ӿ�����
	float c_x, c_y;//������������
	int m_HP;
	int m_lr;//0Ϊ��1Ϊ��
	int m_curAction;//��ǰ���� 
	int m_Sequenceframes;//��ǰ֡��
	enum { MOVE, KILL , EAT , AUTO };//�ܶ�����
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


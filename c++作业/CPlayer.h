#pragma once

#include <string>
#include "Config.h"
#define CUR_ACT m_curAction*2+m_lr
#define CUR_IMG m_Frames[CUR_ACT][m_Sequenceframes]

class CPlayer {
public:
	string name;
	int m_x, m_y;//�����ӿ�����
	int c_x, c_y;//������������
	int m_HP;
	int m_lr;//0Ϊ��1Ϊ��
	int m_curAction;//��ǰ���� 
	int m_Sequenceframes;//��ǰ֡��
	enum { WAIT, MOVE, AUTO };//�ܶ�����
	IMAGE* m_Frames[AUTO*2][100];// m_Frames[����][֡]

public:
	CPlayer();

	void Init();
	void Show();
	void* Fire(int  ,int );
	void Move(int direct, int step);
};


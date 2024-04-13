#pragma once

#include <string>
#include "Config.h"
#define CUR_ACT m_curAction*2+m_lr
#define CUR_IMG m_Frames[CUR_ACT][m_Sequenceframes]

class CPlayer {
public:
	string name;
	int m_x, m_y;//这是视口坐标
	int c_x, c_y;//这是世界坐标
	int m_HP;
	int m_lr;//0为右1为左
	int m_curAction;//当前动作 
	int m_Sequenceframes;//当前帧数
	enum { WAIT, MOVE, AUTO };//总动作数
	IMAGE* m_Frames[AUTO*2][100];// m_Frames[动作][帧]

public:
	CPlayer();

	void Init();
	void Show();
	void* Fire(int  ,int );
	void Move(int direct, int step);
};


#pragma once
#include "CGameFrame.h"
#include "CPlayer.h"
#include "CBack.h"
#include "CListBullet.h"
#include "CListFoe.h"
#include "UI.h"
#include "ClistTree.h"

class WinApp :public CGameFrame {
public:
	CBack m_Back;
	CPlayer m_player;
	CListBullet m_listbullet;
	CListFoe m_listFoe;
	ClistTree m_listTree;
	UI ui;
public:
	WinApp();
	~WinApp();

	virtual void On_Init();
	virtual void On_Paint();
	virtual void On_Close();
	virtual void AddMsgMap();
public:
	void On_WM_LBUTTONDOWN(int, int);
	void On_WM_KEYDOWN(int key);
	void On_WM_TIMER(WPARAM, LPARAM);
	void SteTimer();
	void KillTime();
	void ShowUI();

};
#pragma once
#include <easyx.h>
//#include <graphics.h>
#include <Windowsx.h>
#include <iostream>
#include <map>
//#include <list>
using namespace std;

#define EX_MOUSE 1
#define EX_KEY 2
#define EX_CHAR 4
#define EX_WINDOW 8

#define ADD_MSG_MAP(MSGID,MSGTYPE,CLASS)\
    m_msgMap[MSGID].MsgType = MSGTYPE;\
    m_msgMap[MSGID].p_fun_##MSGTYPE = (P_FUN_##MSGTYPE) &CLASS::On_##MSGID;

#define WND_PARAM(W,H,X,Y,TITLE)\
    int width = W;\
    int height = H;\
    int pos_x = X;\
    int pos_y = Y;\
    const WCHAR* pTitle = TITLE;\

#define CREAIE_OBJECT(CLASS)\
    CGameFrame* CreateObject() {\
	     return new CLASS;\
    }\

class CGameFrame
{
public:
	HWND m_hwnd;
	bool m_isQuit;

	typedef void (CGameFrame::* P_FUN_EX_MOUSE)(int, int);
	typedef void (CGameFrame::* P_FUN_EX_KEY)(int);
	typedef void (CGameFrame::* P_FUN_EX_WINDOW)(WPARAM, LPARAM);

	struct MsgTypeFun {
		UINT MsgType;
		union {
			P_FUN_EX_MOUSE p_fun_EX_MOUSE;
			P_FUN_EX_KEY p_fun_EX_KEY;
			P_FUN_EX_WINDOW p_fun_EX_WINDOW;
		};
	};

	map<UINT, MsgTypeFun> m_msgMap;



	CGameFrame();
	virtual ~CGameFrame();

	void InitGame(int width, int height, int x, int y, const WCHAR* p);

	virtual void AddMsgMap();

	void PaintGame();


	static LRESULT CALLBACK RunGame(HWND hWindow, UINT uMsg, WPARAM wPrarm, LPARAM lparam);


	void On_WM_CLOSE(WPARAM, LPARAM);

	virtual void On_Init() = 0;
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;
	/*virtual void On_WM_LBUTTONDOWN(int x, int y) {}
	virtual void On_WM_RBUTTONDOWN(int x, int y) {}
	virtual void On_WM_KEYDOWN(int vkcode) {}*/
};


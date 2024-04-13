#pragma once
#include <graphics.h>
#include <iostream>
using namespace std;
void putimagePNG(int  picture_x, int picture_y, IMAGE* picture);//Í¸Ã÷±ßÔµÊµÏÖ
int getDelay();
bool Ext(WCHAR* );

#define PI 3.1415926

#define WIN_DPI 1.0 //ÆÁÄ»DPI
#define WIN_WIDTH 1280.0
#define WIN_HIGHT 720.0
#define WIN_XPIANYI 200.0
#define WIN_YPIANYI 120.0
#define WIN_XWEIZHI (WIN_WIDTH/WIN_DPI)
#define WIN_YWEIZHI (WIN_HIGHT/WIN_DPI)

#define GAME_DATA_TIMERID 0
#define GAME_DATA_INTERVAL 1

#define USER_OPERATE_TIMERID 1
#define USER_OPERATE_INTERVAL 1

#define PALYER_SHOW_TIMERID 2
#define PALYER_SHOW_INTERVAL 10
#define PLAYER_WIDTH 170
#define PLAYER_HIGHT 170
#define PLAYER_XWEIZHI (PLAYER_WIDTH/WIN_DPI)
#define PLAYER_YWEIZHI (PLAYER_HIGHT/WIN_DPI)
#define OLAYER_STEP 5

#define BACK_WIDTH 10240
#define BACK_HIGHT 6400

#define BULLET_MOVE_TIMERID 3
#define BULLET_SMOVE_INTERVAL 1
#define BULLET_MOVE_STEP 20.0
#define BULLET_WIDTH 6
#define BULLET_HEIGHT 20
#define BULLET_HIT 10

#define CREATE_FOE_TIMERID 4
#define CREATE_FOE_INTERVAL 2500
#define FOE_MOVE_STEP 5.0
#define FOE_MOVE_TIMERID 5
#define FOE_MOVE_INTERVAL 10
#define FOE_WIDTH 134
#define FOE_HIGHT 144
#define FOE_SHOW_TIMERID 5
#define FOE_SHOW_INTERVAL 1


#define CHECK_HIT_TIMERID 6
#define CHECK_HIT_INTERVAL 5

#define FOE_DIE_TIMERID 7
#define FOE_DIE_INTERVAL 1000
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <time.h>
#include <math.h>

#pragma warning (disable : 4819)

#include <d3d9.h>
//#include <d3dx9.h>

#include <DxLib.h>

bool PushHitKey( int key );
bool CheckMouseInput( int button = MOUSE_INPUT_LEFT|MOUSE_INPUT_RIGHT );
bool PushMouseInput( int button = MOUSE_INPUT_LEFT|MOUSE_INPUT_RIGHT );
int GetMouseX();
int GetMouseY();
int GetMouseMoveX();
int GetMouseMoveY();
float TO_RADIAN( float degree );
float TO_DEGREE( float radian );

// ゲームの段階用の変数
enum GameScene
{
	TITLE,
	STAGE,
	GOAL,
};
//次に行きたいシーンを入れる関数
extern int scene_next;
//	今どこのシーンにいるのかを見る用の変数
extern int scene_num;

#define MAP_W   100
#define MAP_H   11
#define BOX_SIZE 32

//命名規則
//定数		アッパースネークケース	UPPER_SNAKE_CASE
//関数				パスカルケース	　Pascal_Case();	
//変数名				スネークケース	　　 snake_case;
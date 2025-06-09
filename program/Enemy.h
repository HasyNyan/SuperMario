#pragma once
#include"Game.h"
#include"Kinoko.h"
class Enemy :public Kinoko
{
public:

	int _rotation = 0;
	//bool _isMove = false;

	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;

	void CheckMap(int map[MAP_H][MAP_W], float bVecY[MAP_H][MAP_W])override;

	void MoveOn(float x, float y)override;

	void GetMapOffSetX(float x)override;
};

constexpr int ENEMY_MOVE_SPEED_X = 1;

constexpr int ENEMY_MOVE_SPEED_Y = 4;
//プレイヤーから見てのクリボーが出現する距離
constexpr int ENEMY_DISTANCE = SCREEN_W / 2;
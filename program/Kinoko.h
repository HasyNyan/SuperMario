#pragma once
#include "Object.h"
#include "Main.h"
#include "Map.h"

class Kinoko : public Object
{
public:
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;

	virtual void CheckMap(int map[MAP_H][MAP_W] , float bVecY[MAP_H][MAP_W]);

	virtual void MoveOn(float x, float y);
	bool _isMove = false;

	virtual void GetMapOffSetX(float x);
	float _mapOffSetX = 0.0f;


	Float2 _vec;

	Float2 _boxSize = {BOX_SIZE , BOX_SIZE};


	bool _left = false;

};

#define K_MOVE_SPEED_X 1;

#define K_MOVE_SPEED_Y 4;


#pragma once
#include "Object.h"
#include "Main.h"
#include "Map.h"
#include "Game.h"

class Fire : public Object
{
public:
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;

	void SetPos(float x, float y, bool playWay);

	void CheckMap(int map[MAP_H][MAP_W] ,Fire *& fire );
	float _mapOffSetX = 0.0f;

	void GetOffSetX(float x);

	float _logY;

	Float2 _vec = {0,0};
	bool _way = false;

	Float2 _boxSize = { 16,16 };


};


#define F_MOVE_SPEED 8;
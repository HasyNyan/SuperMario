#pragma once
#include "Object.h"
#include "Map.h"
#include "Main.h"
#include "Float2.h"
#include "Kinoko.h"
#include "Hit.h"

#define PLAYER_W 28
#define PLAYER_H 28
#define MOVE_SPEED 3

class Player:public Object
{
public:
	Float2 _vec;
	bool _isOnGround = false;


	Float2 _boxSize = { PLAYER_W , PLAYER_H };

	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;

	void CheckMap(Map & map,Kinoko & kinoko);
	float _mapOffSetX = 0.0f;
};





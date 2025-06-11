#pragma once
#include "Object.h"
#include "Map.h"
#include "Main.h"
#include "Float2.h"
#include "Kinoko.h"
#include "Flower.h"
#include "Fire.h"
#include "Hit.h"

#define PLAYER_W 28
#define PLAYER_H 28
#define MOVE_SPEED 3

enum
{
	MODE_SMALL,
	MODE_BIG,
	MODE_FIRE,
};

class Player:public Object
{

public:
	Float2 _vec;
	bool _isOnGround = false;

	//プレイヤーのサイズ
	Float2 _boxSize[3] = { {PLAYER_W , PLAYER_H},
		                   {PLAYER_W , PLAYER_H * 2},
		                   {PLAYER_W , PLAYER_H * 2} 
	};

	int _modeImg[3] = { -1 } ;

	int _mode = MODE_SMALL;

	bool _leftWay = false;

	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;



	void CheckMap(Map & map,Kinoko *& kinoko 
		      ,Flower *& flower );

	void FireBall(Fire* fire[2]);


	float _mapOffSetX = 0.0f;
};







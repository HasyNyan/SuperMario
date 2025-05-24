#pragma once
#include"Enemy.h"
class Enemy_Turtle:public Enemy
{
public:
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;
};
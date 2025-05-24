#pragma once
#include"Object.h"
class Enemy :public Object
{
public:
	float _speed;

	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;
};
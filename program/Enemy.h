#pragma once
#include"Object.h"
class Enemy :public Object
{
public:
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;
};
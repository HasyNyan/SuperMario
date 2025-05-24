#pragma once
#include "Object.h"
class Player:public Object
{
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;
};
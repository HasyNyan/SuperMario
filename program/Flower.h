#pragma once
#include "Object.h"
#include "Main.h"

class Flower : public Object
{
public:
	void Init()override;
	void Update()override;
	void Render()override;
	void Exit()override;

	void SetPos(float x, float y);

	void GetMapOffSetX(float x);
	float _mapOffSetX = 0.0f;

	Float2 _boxSize = { BOX_SIZE,BOX_SIZE };

};
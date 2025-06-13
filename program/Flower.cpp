#include "Flower.h"
#include "Fire.h"

void Flower::Init() {
	_img = LoadGraph("data/flower.png");
}

void Flower::Update()
{
}

void Flower::Render()
{
	DrawGraphF(_pos.x + _mapOffSetX, _pos.y, _img, TRUE);
}

void Flower::Exit()
{
	DeleteGraph(_img);
}





void Flower::SetPos(float x, float y)
{
	_pos.Set(x, y);
}

void Flower::GetMapOffSetX(float x) {
	_mapOffSetX = x;
}

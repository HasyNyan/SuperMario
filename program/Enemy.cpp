#include "Main.h"
#include "Game.h"
#include "Enemy.h"

void Enemy::Init()
{
	_img = LoadGraph("data/npc.png");
}

void Enemy::Update()
{
}

void Enemy::Render()
{
	DrawGraph(SCREEN_W / 2, SCREEN_H / 2, _img, TRUE);
}

void Enemy::Exit()
{
	DeleteGraph(_img);
}

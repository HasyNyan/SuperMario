#include "Main.h"
#include "Game.h"
#include "Stage.h"
#include "Enemy.h"

Enemy enemy;

void Stage::Init()
{
	enemy.Init();
}

void Stage::Update()
{
	enemy.Update();
}

void Stage::Render()
{
	enemy.Render();
}

void Stage::Exit()
{
	enemy.Exit();
}

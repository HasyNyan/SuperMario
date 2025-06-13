#include "Main.h"
#include "Game.h"
#include "Stage.h"
#include "Map.h"
#include "Player.h"
#include "Kinoko.h"
#include "Flower.h"
#include "Fire.h"
#include "Enemy.h"

//マップ
Map map01;

//マリオ
Player mario;

//キノコ
Kinoko * kinoko;

Flower * flower;

Fire* fire[2];

//クリボー
Enemy* enemy;

void Stage::Init()
{
	//マリオ
	mario.Init();
	//マップ
	map01.Init();

	kinoko = nullptr;
	flower = nullptr;

	for (int i = 0; i < 2; i++)
	{
		fire[i] = nullptr;
	}

	
	enemy = nullptr;

}

void Stage::Update()
{
	//プレイヤー
	mario.Update();
	mario.CheckMap(map01, kinoko, flower);

	mario.FireBall(fire);




	//マップ
	map01.Update(mario._pos.x);

	//キノコ
	if (kinoko)
	{
		kinoko->GetMapOffSetX(map01._offSetX);
		kinoko->Update();
		kinoko->CheckMap(map01.stageData, map01._vecY);
	}

	//花
	if (flower)
	{
		flower->GetMapOffSetX(map01._offSetX);
	}

	//FIREBALL
	for (int i = 0; i < 2; i++) {

		if (fire[i])
		{
			fire[i]->GetOffSetX(map01._offSetX);
			fire[i]->Update();
			fire[i]->CheckMap(map01.stageData, fire[i]);
		}
	}
	//クリボー
	if (enemy)
	{
		enemy->GetMapOffSetX(map01._offSetX);
		enemy->Update();
		enemy->CheckMap(map01.stageData, map01._vecY);
		enemy->SearchEnemy(map01.stageData, map01._vecY);
	}

}

void Stage::Render()
{
	//マップ
	map01.Render();

	//FIREBALL
	for (int i = 0; i < 2; i++) {
		if (fire[i])
		{
			fire[i]->Render();
		}
	}


	//マリオ
	mario.Render();

	//キノコ
	if (kinoko)
		kinoko->Render();
	
	//花
	if (flower)
	{
		flower->Render();
	}

	//クリボー
	if (enemy)
	{
		enemy->Render();
	}



	//debug
	DrawString(0, 0, "STAGE01", GetColor(255, 255, 255));
}

void Stage::Exit()
{
	mario.Exit();
	//マップ
	map01.Exit();

	if (kinoko)
	{
		kinoko->Exit();
		delete kinoko;
		kinoko = nullptr;
	}

	if (flower)
	{
		flower->Exit();
		delete flower;
		flower = nullptr;
	}


	for (int i = 0; i < 2; i++) {
		if (fire[i])
		{
			fire[i]->Exit();
			delete fire[i];
			fire[i] = nullptr;
		}
	}
	//クリボー
	if (enemy)
	{
		enemy->Exit();
		delete enemy;
		enemy = nullptr;
	}

}

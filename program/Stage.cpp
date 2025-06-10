#include "Main.h"
#include "Game.h"
#include "Stage.h"
#include "Map.h"
#include "Player.h"
#include "Kinoko.h"
#include "Enemy.h"

//マップ
Map map01;

//マリオ
Player mario;

//キノコ
Kinoko kinoko;
//クリボー
Enemy enemy;

void Stage::Init()
{
	//マリオ
	mario.Init();
	//マップ
	map01.Init();
	//キノコ
	kinoko.Init();
	//クリボーの初期化処理
	enemy.Init();

}

void Stage::Update()
{
	//プレイヤー
	mario.Update();
	mario.CheckMap(map01,kinoko);

	//マップ
	map01.Update(mario._pos.x);

	//キノコ
	kinoko.Update();
	kinoko.CheckMap(map01.stageData , map01._vecY);
	kinoko.GetMapOffSetX(map01._offSetX);
	//クリボーの更新処理
	enemy.Update();
	enemy.CheckMap(map01.stageData, map01._vecY);
	enemy.GetMapOffSetX(map01._offSetX);
}

void Stage::Render()
{
	//マップ
	map01.Render();

	//マリオ
	mario.Render();

	//キノコ
	kinoko.Render();
	//クリボーの描画処理
	enemy.Render();
	//debug
	DrawString(0, 0, "STAGE01", GetColor(255, 255, 255));

}

void Stage::Exit()
{
	mario.Exit();
	//マップ
	map01.Exit();

	kinoko.Exit();
	//クリボーの終了処理
	enemy.Exit();
}

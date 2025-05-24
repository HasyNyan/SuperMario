#include "Main.h"
#include "Game.h"
#include "Hit.h"
//それぞれのヘッダーファイルを呼ぶ
#include "Title.h"
#include "Stage.h"
#include "Goal.h"

//クラス宣言
Title title;
Stage stage;
Goal  goal;
//---------------------------------------------------------------------------------
//	初期化処理
//---------------------------------------------------------------------------------
void GameInit()
{
	scene_num = TITLE;
	scene_next = TITLE;
	title.Init();
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void GameUpdate()
{
	//	今のシーン番号と次に行きたいシーン番号が
	//	違っている時だけこの処理を呼びます
	if (scene_num != scene_next)
	{
		//	今のシーン番号を次の番号に切り替えて
		scene_num = scene_next;
		//	そのシーンに合わせた初期化処理を呼びます
		switch (scene_num)
		{
		case TITLE:
			title.Init();
			break;
		case STAGE:
			stage.Init();
			break;
		case GOAL:
			goal.Init();
			break;
		}
	}
	//今のシーンに合わせた更新処理を呼ぶ
	switch (scene_num)
	{
	case TITLE:
		title.Update();
		break;
	case STAGE:
		stage.Update();
		break;
	case GOAL:
		goal.Update();
		break;
	}
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void GameRender()
{
	//今のシーンに合わせた更新処理を呼ぶ
	switch (scene_num)
	{
	case TITLE:
		title.Render();
		break;
	case STAGE:
		stage.Render();
		break;
	case GOAL:
		goal.Render();
		break;
	}
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void GameExit()
{
	//今のシーンに合わせた更新処理を呼ぶ
	switch (scene_num)
	{
	case TITLE:
		title.Exit();
		break;
	case STAGE:
		stage.Exit();
		break;
	case GOAL:
		goal.Exit();
		break;
	}
}
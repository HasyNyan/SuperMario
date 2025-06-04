#include "Main.h"
#include "Game.h"
#include "Title.h"
//=================================================================================
//	タイトル画面の処理
//=================================================================================
////タイトル用の変数
//int title_image;
//int title_x;
//int title_y;
////タイトル名用の変数
//int name_image;
//int name_x;
//float name_y;
//bool  is_Title_Time;
Game scene_title;
//---------------------------------------------------------------------------------
//	初期化
//---------------------------------------------------------------------------------
void Title::Init()
{
	//タイトル用変数の初期化
	_img = LoadGraph("data/bg/title_bg.png");
	_x = 0;
	_y = 0;
	//タイトル名用の変数の初期化
	//name_image = LoadGraph("data/title_name.bmp");
	//name_x = 700 / 2;
	//name_y = 0.0f;
	//is_Title_Time = FALSE;
}
//---------------------------------------------------------------------------------
//	更新処理
//---------------------------------------------------------------------------------
void Title::Update()
{
	//name_y = name_y + 1.5f;
	if (PushHitKey(KEY_INPUT_SPACE))
	{
		//if (is_Title_Time == TRUE)
		//{
			scene_title.ChangeGameScene(scene_title.STAGE);
		//}
	}

	//	if (name_y >= 150.0f)
		//{
		//	is_Title_Time = TRUE;
		//	name_y = 150.0f;
		//}
}
//---------------------------------------------------------------------------------
//	描画処理
//---------------------------------------------------------------------------------
void Title::Render()
{
	DrawGraph(_x, _y, _img, TRUE);	//タイトル画面の背景描画

	////DrawGraph(name_x, name_y, name_image, TRUE);
	//SetFontSize(50);
	//int font_t = GetDrawStringWidth("アーチャー物語", (int)strlenDx("アーチャー物語"));
	//DrawString(SCREEN_W / 2 - font_t / 2, SCREEN_H / 2 - 32 / 2, "アーチャー物語",
	//	GetColor(255, 255, 255));
	//SetFontSize(30);
	//int font_s = GetDrawStringWidth("Spaceを押してスタート！", (int)strlenDx("Spaceを押してスタート！"));
	//DrawString(SCREEN_W / 2 - font_s / 2, SCREEN_H / 2 + 200, "Spaceを押してスタート！",
	//	GetColor(255, 255, 255));
	//SetFontSize(16);
}
//---------------------------------------------------------------------------------
//	終了処理
//---------------------------------------------------------------------------------
void Title::Exit()
{
	DeleteGraph(_img);
}
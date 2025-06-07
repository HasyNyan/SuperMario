#include "Map.h"
#include "Main.h"
#include "Game.h"
#include "Player.h"
Map map[MAP_H][MAP_W];



void Map::Init()
{
	//マップの画像
	_mapImg[MAP_EMPTY] = -1;
	_mapImg[MAP_BLOCK] = LoadGraph("data/02.png");
	_mapImg[MAP_GROUND] = LoadGraph("");
	_mapImg[MAP_QUESTION] = LoadGraph("data/01.png");
	_mapImg[MAP_USED] = LoadGraph("data/14.png");
	_mapImg[MAP_BRICK] = LoadGraph("");

	//マップの初期化
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++) {
			int num = stageData[y][x];

			map[y][x]._num = num;           //マップの種類
			map[y][x]._img = _mapImg[num];  //画像
			map[y][x]._pos.x = (float)x * BOX_SIZE;  //Ｘ座標
			map[y][x]._pos.y = (float)y * BOX_SIZE;  //Ｙ座標

			_vecY[y][x] = 0;
		}
	}
}

void Map::Update(float playX)
{
	//if (CheckHitKey(KEY_INPUT_A)) _offSetX--;
	//畫面スクロール
	if (CheckHitKey(KEY_INPUT_RIGHT) && playX > -_offSetX + SCREEN_W / 2)
	{
		_offSetX -= MOVE_SPEED ;
	}	
	

	//マップをupdateする
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			//突かれたブロックを元に戻す
			if (_vecY[y][x] < 0)
			{
				_vecY[y][x] += 1.0f; 
				if (_vecY[y][x] > 0)
					_vecY[y][x] = 0; 
			}

			map[y][x]._pos.y = (float)y * BOX_SIZE + _vecY[y][x];

			map[y][x]._num = stageData[y][x];
			map[y][x]._img = _mapImg[map[y][x]._num];
		}
	}

	//debug
	DrawFormatString(0, 40, GetColor(255, 255, 255),"%f", playX);
}

void Map::Render()
{
	//マップの描画
	for (int y = 0; y < MAP_H; y++)
	{
		for (int x = 0; x < MAP_W; x++)
		{
			DrawGraphF(map[y][x]._pos.x + _offSetX, map[y][x]._pos.y, map[y][x]._img, TRUE);
		}
	}
}

void Map::Exit()
{
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(_mapImg[i]);
	}
}

void Map::PushBlock(int y, int x)
{
	_vecY[y][x] -= 10;
}

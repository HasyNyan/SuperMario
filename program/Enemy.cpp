#include "Main.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
 
Player obj;

void Enemy::Init()
{
	_isMove = false;
	_pos.Set(-500.0f,- 500.0f);
	_img = LoadGraph("data/enemy.png");
    _rotation = 0;
}

void Enemy::Update()
{
	if (_isMove)
	{
		//右に移動
		if (_left)
		{
			_vec.x = ENEMY_MOVE_SPEED_X;
		}
		else
		{
			_vec.x = ENEMY_MOVE_SPEED_X;
		}
		_pos.x += _vec.x;
		_pos.y += _vec.y;
	}
}

void Enemy::Render()
{
	DrawRotaGraphF(_pos.x + _mapOffSetX, _pos.y,1,_rotation, _img, TRUE);
}

void Enemy::Exit()
{
	DeleteGraph(_img);
}

void Enemy::CheckMap(int map[MAP_H][MAP_W], float bVecY[MAP_H][MAP_W])
{
    if (!_isMove) return;

    //クリボーの左右上下
    float  left = _pos.x;
    float  right = _pos.x + BOX_SIZE;
    float  top = _pos.y;
    float  bottom = _pos.y + BOX_SIZE;

    //マップの配列外しないように
    int startX = (int)(left / BOX_SIZE);
    if (startX < 0) startX = 0;

    int startY = (int)(top / BOX_SIZE);
    if (startY < 0) startY = 0;

    int endX = (int)((right - 1) / BOX_SIZE);
    if (endX > MAP_W - 1) endX = MAP_W - 1;

    int endY = (int)((bottom - 1) / BOX_SIZE);
    if (endY > MAP_H - 1) endY = MAP_H - 1;

    // Ｙ方向
    for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
            if (map[y][x] == MAP_EMPTY) continue;

            //ブロックの上下左右
            float blockTop = (float)y * BOX_SIZE;
            float blockBottom = blockTop + BOX_SIZE - 1;


            //上から下
            if (_vec.y > 0) {
                _pos.y = blockTop - BOX_SIZE;
                _vec.y = 0;
            }

        }
    }

    //X方向
    left = _pos.x;
    right = _pos.x + BOX_SIZE;
    top = _pos.y;
    bottom = _pos.y + BOX_SIZE;

    //座標を配列化する
    //左
    startX = (int)(left / BOX_SIZE);
    //マップの配列外しないように
    if (startX < 0) startX = 0;
    //上
    startY = (int)(top / BOX_SIZE);
    if (startY < 0) startY = 0;
    //右
    endX = (int)(right - 1) / BOX_SIZE;
    if (endX > MAP_W - 1) endX = MAP_W - 1;
    //下
    endY = (int)((bottom - 1) / BOX_SIZE);
    if (endY > MAP_H - 1) endY = MAP_H - 1;

    for (int y = startY; y <= endY; y++)
    {
        for (int x = startX; x <= endX; x++)
        {
            if (map[y][x] == MAP_EMPTY) continue;

            //障害物との当たり判定
            float blockLeft = (float)x * BOX_SIZE;
            float blockRight = blockLeft + BOX_SIZE;

            //左がら右
            if (_vec.x > 0)
            {
                _pos.x = blockLeft - BOX_SIZE;
                _left = true;
            }
            //右から左
            else if (_vec.x < 0)
            {
                _pos.x = blockRight;
                _left = false;
            }
        }
    }

    //足元の座標（多次元配列）
    int footY  = (int)(_pos.y + BOX_SIZE) / BOX_SIZE;
    int footX1 = (int)(_pos.x) / BOX_SIZE;
    int footX2 = (int)(_pos.x + BOX_SIZE - 1) / BOX_SIZE;

    //左下か右下がブロックに突かれるのチェック
    bool isLeftHit = bVecY[footY][footX1] < 0;
    bool isRightHit = bVecY[footY][footX2] < 0;

    if (isLeftHit || isRightHit) //突かれたら
    {
        _rotation = 180.0f;

        ////飛ぶ
        //_vec.y = -15.0f;
        //
        ////左下が突かれる
        //if (isLeftHit && !isRightHit)
        //{
        //    //右へ
        //    _left = false;
        //}
        ////右下が突かれる
        //else if (isRightHit && !isLeftHit)
        //{
        //    //左へ
        //    _left = true;
        //}
    }

    //両足の下になんもない場合
    if (map[footY][footX1] == MAP_EMPTY || map[footY][footX2] == MAP_EMPTY)
    {
        //重力
        _vec.y += 1.0f;
    }

}
//プレイヤーから見てクリボーの出現位置に来たらクリボーを出現させる
void Enemy::SearchEnemy(int map[MAP_H][MAP_W], float bVecY[MAP_H][MAP_W])
{
    //クリボーの左右上下
    float  left = _pos.x;
    float  right = _pos.x + BOX_SIZE;
    float  top = _pos.y;
    float  bottom = _pos.y + BOX_SIZE;

    //マップの配列外しないように
    int startX = (int)(left / BOX_SIZE);
    if (startX < 0) startX = 0;

    int startY = (int)(top / BOX_SIZE);
    if (startY < 0) startY = 0;

    int endX = (int)((right - 1) / BOX_SIZE);
    if (endX > MAP_W - 1) endX = MAP_W - 1;

    int endY = (int)((bottom - 1) / BOX_SIZE);
    if (endY > MAP_H - 1) endY = MAP_H - 1;

    for (int y = startY; y <= endY; y++)
    {
        for (int x = startX; x <= endX; x++)
        {
            //プレイヤーからみてクリボーの出現距離をプラス
            float enemy_distance = obj.GetPlayerPosX() + ENEMY_DISTANCE;
            //プレイヤーから見たクリボーの距離を多次元配列の座標に
            int enemy_block_x = (int)(enemy_distance / BOX_SIZE);
            if (map[y][enemy_block_x] == MAP_ENEMY) 
            {
                map[y][enemy_block_x] = MAP_EMPTY;
                //MoveOn();
            }

        }
    }

}

void Enemy::MoveOn(float x, float y)
{
    _pos.Set(x, y);
    _isMove = true;
}

void Enemy::GetMapOffSetX(float x)
{
    _mapOffSetX = x;
}

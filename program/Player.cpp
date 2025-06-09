#include "Player.h"

Player player;
void Player::Init()
{
	_pos = { 0,0 };
	_img = LoadGraph("data/player.png");
    _isOnGround = false;
}

void Player::Update()
{
    //左移動
    if (CheckHitKey(KEY_INPUT_LEFT)){

        if (_pos.x + _mapOffSetX > 0.0f)
        {
            _vec.x = -MOVE_SPEED;
        }
        else
        {
            _vec.x = 0.0f;
            _pos.x = -_mapOffSetX;
        }
    }
    //右移動
    else if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        _vec.x = MOVE_SPEED;
    }
    else
    {
       _vec.x = 0;
    }

    //飛ぶ
    if (_isOnGround && PushHitKey(KEY_INPUT_UP)) 
    {
        _vec.y = -15.0f;
    }

    //重力
    if (!_isOnGround)
    {
        _vec.y += 0.5f;
    }
}

void Player::Render()
{
    //プレイヤー描画
	DrawGraphF(_pos.x + _mapOffSetX, _pos.y, _img, TRUE);
}
void Player::Exit()
{
    DeleteGraph(_img);
}


void Player::CheckMap(Map & map, Kinoko &kinoko ,Enemy &enemy)
{

    _mapOffSetX = map._offSetX;

    // Y方向
    _pos.y += _vec.y;

    //プレイヤーの左右上下
    float  left = _pos.x;
    float  right = _pos.x + PLAYER_W;
    float  top = _pos.y;
    float  bottom = _pos.y + PLAYER_H;

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
            if (map.stageData[y][x] == MAP_EMPTY) continue;

            //ブロックの上下左右
            float blockTop    = (float)y * BOX_SIZE;
            float blockBottom = blockTop + BOX_SIZE;
            float blockLeft   = (float)x * BOX_SIZE;
            float blockRight  = blockLeft + BOX_SIZE;

            //下から上
            if (_vec.y < 0) {

                //プレイヤーがブロックの左が右の判定
                bool atLeft  = (right - blockLeft) < (PLAYER_W * 0.5f);
                bool atRight = (blockRight - left) < (PLAYER_W * 0.5f);

                //ブロックの左右が空いてるかどうかの判定
                bool checkEmptyLeft  = (x > 0)         && (map.stageData[y][x - 1] == MAP_EMPTY);
                bool checkEmptyRight = (x < MAP_W - 1) && (map.stageData[y][x + 1] == MAP_EMPTY);

                //左が右に滑られる判定
                bool slideLeft   = atLeft  && checkEmptyLeft;
                bool slideRight  = atRight && checkEmptyRight;

                //左に滑る
                if (slideLeft) {
                    _pos.x = blockLeft - PLAYER_W - 1;
                }
                //右に滑る
                else if (slideRight) {
                    _pos.x = blockRight;
                }
                //止める
                else {
              
                    _vec.y = 0;
                    _pos.y = blockBottom;
                }
    
                //プレイヤーの中心をとる
                float playerMidX = _pos.x + PLAYER_W * 0.5f;

                //プレイヤーの中心を多次元配列にする
                int midBlockX = (int)(playerMidX / BOX_SIZE);

                //？？？BOXとの当たり判定
                if (map.stageData[y][midBlockX] == MAP_QUESTION ) {

                    map.stageData[y][midBlockX] = MAP_USED;
                    kinoko.MoveOn((float)midBlockX * BOX_SIZE, (float)(y - 1) * BOX_SIZE);
                }

                //ブロックとの当たり判定
                if (map.stageData[y][midBlockX] == MAP_BLOCK) {
                    map.PushBlock(y, midBlockX);
                }
            }

            //上から下
            else if (_vec.y > 0) {
                _pos.y = blockTop - PLAYER_H;
                _vec.y = 0;
          
            }
        }
    }

     //X方向
    _pos.x += _vec.x;

    left = _pos.x;
    right = _pos.x + PLAYER_W;
    top = _pos.y;
    bottom = _pos.y + PLAYER_H;

    //プレイヤーの座標を配列化する
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

            //プレイヤーの中心をとる
            float playerMidX = _pos.x + PLAYER_W * 0.5f;

            //プレイヤーの中心を多次元配列にする
            int midBlockX = (int)(playerMidX / BOX_SIZE);
            //敵が出現する距離を多次元配列に合わせる
            int enemy_distance = (int)(ENEMY_DISTANCE / BOX_SIZE);
            //プレイヤーから一定範囲内に来たらクリボーを動かす
           // if (map.stageData[y][midBlockX + enemy_distance ] == MAP_ENEMY) {
           //     enemy.MoveOn((float)midBlockX + enemy_distance * BOX_SIZE, (float)(y - 1) * BOX_SIZE);
           // }

            //障害物との当たり判定
            if (map.stageData[y][x] == MAP_EMPTY) continue;
            
            float blockLeft = (float)x * BOX_SIZE;
            float blockRight = blockLeft + BOX_SIZE;

            //左がら右
            if (_vec.x > 0) _pos.x = blockLeft - PLAYER_W;

            //右から左
            else if (_vec.x < 0) _pos.x = blockRight;

            _vec.x = 0;
            
        }
    }

    //足元の座標（多次元配列）
    int footY  = (int)(_pos.y + PLAYER_H) / BOX_SIZE;
    int footX1 = (int)(_pos.x ) / BOX_SIZE;
    int footX2 = (int)(_pos.x + PLAYER_W - 1 ) / BOX_SIZE;

    //足元のがなんもない時飛べない処理
    _isOnGround = false;
    
    if (map.stageData[footY][footX1] != MAP_EMPTY || map.stageData[footY][footX2] != MAP_EMPTY)
    {
        _isOnGround = true;
    }


    //キノコとプレイヤーとの当たり判定
    if (CheckBoxHit(_pos,_boxSize, kinoko._pos, kinoko._boxSize))
    {
        kinoko.Init();
    }


    //debug
    DrawBoxAA(left + _mapOffSetX, top, right + _mapOffSetX, bottom, GetColor(255, 255, 255), 0);

    for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
            float drawX = (float)x * BOX_SIZE + _mapOffSetX;
            float drawY = (float)y * BOX_SIZE;
           DrawBoxAA(drawX, drawY, drawX + BOX_SIZE, drawY + BOX_SIZE, GetColor(255, 0, 0), FALSE);
        }
    }

    DrawFormatString(0, 20, GetColor(255, 255, 255), "X1;%d,Y1;%d,X2;%d,Y2;%d,offsetx%f  G:%d VX%f,VY%f", 
                                            startX, startY, endX, endY , _mapOffSetX,_isOnGround,_vec.x , _vec.y);
}


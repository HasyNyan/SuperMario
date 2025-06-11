#include "Fire.h"

void Fire::Init()
{
	_img = LoadGraph("data/fireball.png");
}

void Fire::Update()
{
    _logY = _pos.y;

    if (_way)
    {
        _vec.x = -F_MOVE_SPEED;
    }
    else if (!_way)
    {
        _vec.x = F_MOVE_SPEED;
    } 
     

    _vec.y++;

    _pos.x += _vec.x;
    _pos.y += _vec.y;



}

void Fire::Render()
{
	DrawGraphF(_pos.x + _mapOffSetX, _pos.y, _img, TRUE);
}

void Fire::Exit()
{
	DeleteGraph(_img);
}

void Fire::SetPos(float x, float y ,bool playWay) {

	_way = playWay;
	_pos.x = x + BOX_SIZE/2;
	_pos.y = y;

}

void Fire::CheckMap(int map[MAP_H][MAP_W], Fire*& fire)
{

    //左右上下
    //Ｙ方向
    float  left = _pos.x;
    float  right = _pos.x + _boxSize.x;
    float  top = _pos.y;
    float  bottom = _pos.y + _boxSize.y ;

    //配列外しないように
    int startX = (int)(left / BOX_SIZE);
    if (startX < 0) startX = 0;

    int startY = (int)(top / BOX_SIZE);
    if (startY < 0) startY = 0;

    int endX = (int)((right - 1) / BOX_SIZE);
    if (endX > MAP_W - 1) endX = MAP_W - 1;

    int endY = (int)((bottom - 1) / BOX_SIZE);
    if (endY > MAP_H - 1) endY = MAP_H - 1;


    for (int y = startY; y <= endY; y++) {
        for (int x = startX; x <= endX; x++) {
            if (map[y][x] == MAP_EMPTY) continue;


            //ブロックの上
            float blockTop     = (float)y * BOX_SIZE;
            float blockBottom  = blockTop + BOX_SIZE;

            //上から下
            //if (_vec.y > 0 && top < blockTop && top < blockBottom) {
            //    _pos.y = blockTop - _boxSize.y;
            //    _vec.y = -6;
            //}

            if (_vec.y > 0 && _logY + _boxSize.y <= blockTop && _pos.y + _boxSize.y >= blockTop) {
                _pos.y = blockTop - _boxSize.y;
                _vec.y = -6;
            }

        }
    }

    //X方向
    left = _pos.x;
    right = _pos.x + _boxSize.x;
    top = _pos.y;
    bottom = _pos.y + _boxSize.y ;

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

            float blockLeft = (float)x * BOX_SIZE;
            float blockRight = blockLeft + BOX_SIZE;


            //左がら右/右から左
            if (_vec.x > 0 || _vec.x < 0)
            {
                //消える
                //_vec.x = 0;
                if (fire)
                {
                    fire->Exit();
                    delete fire;
                    fire = nullptr;
                }
            }
        }
    }

    //消える
    if (_pos.x + _mapOffSetX <= -_boxSize.x || _pos.x + _mapOffSetX >= SCREEN_W)
    {
        if (fire)
        {
            fire->Exit();
            delete fire;
            fire = nullptr;
        }
    }


    //DrawBoxAA(left + _mapOffSetX, top, right + _mapOffSetX, bottom, GetColor(255, 255, 255), 0);

    //for (int y = startY; y <= endY; y++) {
    //    for (int x = startX; x <= endX; x++) {
    //        float drawX = (float)x * BOX_SIZE + _mapOffSetX;
    //        float drawY = (float)y * BOX_SIZE;
    //        DrawBoxAA(drawX, drawY, drawX + BOX_SIZE, drawY + BOX_SIZE, GetColor(255, 0, 0), FALSE);
    //    }
    //}
}


void Fire::GetOffSetX(float x)
{
    _mapOffSetX = x;
}


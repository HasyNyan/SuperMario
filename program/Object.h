#pragma once
#include"Float2.h"

//---------------------------------------------------------------------------------
//	基本クラス
//---------------------------------------------------------------------------------

class Object
{
public:
	int _img;			//データ用のメンバ変数
	Float2 _pos;		//座標

	Object();			//コンストラクタ
	
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};
#pragma once
class Title
{
public:
	int _img;
	int _x;
	int _y;
	
	//タイトルで使う関数の宣言
	void Init();
	void Update();
	void Render();
	void Exit();
};

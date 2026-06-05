#pragma once
#include"Common.h"

class Player
{
public:
	Player();
	void Update();
	void Draw()const;

	void MoveRight(double x);
	void ResetPos();
private:
	Texture chara{ U"image/Chara.png" };

	Vec2 m_charaPos{ 200,500 };
	int32 pat = 0;
	int32 count = 0;

	static constexpr int32 FRAME_W = 48;
	static constexpr int32 FRAME_H = 32;

};

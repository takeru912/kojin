#pragma once
#include"Common.h"
#include"Gauge.h"

class Player
{
public:
	Player();
	void Update();
	void Draw()const;

	void SetGauge(Gauge* gauge);
	bool IsAnimEnd() const;
private:
	Texture chara{ U"image/Chara.png" };

	Vec2 m_charaPos{ 200,500 };

	int pat = 0;
	int patMax = 4;
	int32 count = 0;

	bool m_animEnd = false;

	static constexpr int32 FRAME_W = 48;
	static constexpr int32 FRAME_H = 32;

	int anime = 0;
	int oldAnime = 0;

	Gauge* m_gauge=nullptr;


};

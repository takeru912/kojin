#pragma once
#include"Common.h"
#include"Gauge.h"
#include"NameSpaceScreen.h"
#include"BackGround.h"

class Player
{
public:
	Player();
	void Update(const RectF& ground);
	void Draw()const;

	void SetGauge(Gauge* gauge);
	bool IsAnimEnd() const;

	void StartRunRight();
private:
	Texture chara{ U"image/Chara.png" };

	Vec2 m_charaPos{ 200,445 };

	int pat = 0;
	int patMax = 4;
	int32 count = 0;

	bool m_animEnd = false;

	static constexpr int32 FRAME_W = 48;
	static constexpr int32 FRAME_H = 32;

	int anime = 0;
	int oldAnime = 0;
	int animeSpeed = 0;

	Gauge* m_gauge=nullptr;

	double m_speed = 2000.0;
	bool m_isRunning = false;
	bool m_isScrollStart = false;
	bool m_isFinalRun = false;

public:
	Vec2 GetPos() const { return m_charaPos; };
	void ResetPosition();

	RectF GetRect()const;

	bool IsOutOfScreen() const;
};

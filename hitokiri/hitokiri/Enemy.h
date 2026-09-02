#pragma once
#include"Common.h"


class Enemy
{
public:
	Enemy();
	Enemy(Vec2 pos);
	void Update();
	void Draw()const;

	bool IsDead() const { return m_isDead; }
	void Dead();
	RectF GetRect() const;
	void FadeOut();


    Vec2 GetPos() const;
private:

	struct EnemyData
	{
		Texture idleTextures;
		int32 idleframeCount;
		Texture deadTextures;
		int32 deadframeCount;
	};

	Array<EnemyData> m_enemies
	{
		{Texture { U"image/hone.png" },    7,Texture{U"image/honeDead.png"},    5 },
		{Texture { U"image/kitune.png" },  8,Texture{U"image/kituneDead.png"},  10},
		{Texture { U"image/Ktengu.png" },  6,Texture{U"image/KtenguDead.png"},  6},
		{Texture { U"image/otimusha.png" },6,Texture{U"image/otimushaDead.png"},6},
		{Texture { U"image/tengu.png" },   6,Texture{U"image/tenguDead.png"},   6}
	};

	int32 m_type = 0;
	int32 m_frame = 0;

	Vec2 m_pos;
	
	Stopwatch m_timer{ StartImmediately::Yes };

	bool m_isDead = false;
	double m_alpha = 1.0;
};

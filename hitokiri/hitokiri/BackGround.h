# pragma once
# include "Common.h"

// ゲームシーン
class BackGround
{
public:

	BackGround();

	void update();
	void draw()const;

	void StartScroll();
	bool IsScrolling();
	void StopScroll();

	const RectF& GetPlayGroundRect() const;
private:
	Texture bg{ U"image/BackGround.png" };
	Texture pg{ U"image/playground.png" };

	Vec2 m_pgPos{ 0,700 };
	const int32 y = static_cast<int32>(Scene::Height() * 0.72);
	const int32 h = static_cast<int32>(Scene::Height() * 0.08);	

	RectF m_groundRect;

	double m_bgX = 0;
	double m_pgX = 0;
	bool m_isScroll = false;
	double m_scrollSpeed = 5.0;

};

#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	m_groundRect = Rect{ 0,y,Scene::Width(),h };
}

void BackGround::update()
{

}

void BackGround::draw()const
{
	bg.resized(Scene::Size()).draw();
	pg.resized(Scene::Size()).draw();

	m_groundRect.drawFrame(2, 0, Palette::Red);
}

const RectF& BackGround::GetPlayGroundRect() const
{
	static RectF rect;

	rect = RectF{
		0,
		Scene::Height() * 0.72,
		Scene::Width(),
		Scene::Height() * 0.08
	};

	return rect;
}

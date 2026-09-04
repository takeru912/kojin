#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	const double groundY = Scene::Height() * 0.72;

	m_groundRect = RectF{
		0,
		groundY,
		Scene::Width(),
		Scene::Height() - groundY
	};
}

void BackGround::update()
{
	if (!m_isScroll) return;

	double move = m_scrollSpeed * Scene::DeltaTime();

	m_bgX -= move;
	m_pgX -= move;

	if (m_bgX <= -Scene::Width())
	{
		m_bgX += Scene::Width();
	}

	if (m_pgX <= -Scene::Width())
	{
		m_pgX += Scene::Width();
	}

}

void BackGround::draw()const
{
	
	bg.resized(Scene::Size()).draw(m_bgX, 0);
	bg.resized(Scene::Size()).draw(m_bgX + Scene::Width(), 0);

	pg.resized(Scene::Size()).draw(m_pgX, 0);
	pg.resized(Scene::Size()).draw(m_pgX + Scene::Width(), 0);
	
}

void BackGround::StartScroll()
{
	m_isScroll = true;
}

bool BackGround::IsScrolling()
{
	return m_isScroll;
}

const RectF& BackGround::GetPlayGroundRect() const
{
	return m_groundRect;  
}

void BackGround::StopScroll()
{
	m_isScroll = false;
}

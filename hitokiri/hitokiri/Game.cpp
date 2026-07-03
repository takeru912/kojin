#include "Game.h"


Game::Game(const InitData& init)
	: IScene{ init }
	, m_player()
	, m_gauge()
{
	m_player.SetGauge(&m_gauge);
	
}
void Game::update()
{

	m_gauge.update();
	m_player.Update();

	if (m_player.IsAnimEnd() && !m_waitNextStage)
	{
		m_waitNextStage = true;
		m_clearTimer = 0.0;
	}

	if (m_waitNextStage)
	{
		m_clearTimer += Scene::DeltaTime();

		if (m_clearTimer >= 1.5)
		{
			m_gauge.NextStage();

			m_waitNextStage = false;
		}
	}
}


void Game::draw() const
{
	m_BG.draw();
	// ゲージ描画
	m_gauge.draw();
	m_player.Draw();

}


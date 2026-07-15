#include "Game.h"
#include "NameSpaceScreen.h"


Game::Game(const InitData& init)
	: IScene{ init }
	, m_player()
	, m_gauge()
{
	m_player.SetGauge(&m_gauge);

	CreateEnemies();
}
void Game::update()
{

	m_gauge.update();
	m_player.Update(m_BG.GetPlayGroundRect());

	for (auto& enemy : m_enemies)
	{
		enemy.Update();
	}

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

			CreateEnemies();

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


	for (const auto& enemy : m_enemies)
	{
		enemy.Draw();
	}
}

void Game::CreateEnemies()
{
	m_enemies.clear();

	int32 count = 0;

	switch (m_gauge.GetStage())
	{
	case 1:
		count = 5;
		spacing = 120;
		break;

	case 2:
		count = 10;
		spacing = 80;
		break;

	case 3:
		count = 15;
		spacing = 60;
		break;

	}

	double startX = Screen::WIDTH * 0.26;

	for (int i = 0; i < count; i++)
	{
		
		Vec2 pos
		{
			startX + i * spacing,
			Screen::HEIGHT * 0.55
		};

		m_enemies.emplace_back(Vec2{pos});
	}
}

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


	// 80%到達 → スクロール開始
	if (!m_isScrollStarted &&
		m_player.GetPos().x >= Scene::Width() * 0.8)
	{
		m_BG.StartScroll();

		m_player.ResetPosition();

		m_isScrollStarted = true;
		m_scrollTimer = 0.0;
	}


	// スクロール中
	if (m_isScrollStarted)
	{
		m_scrollTimer += Scene::DeltaTime();

		if (m_scrollTimer >= 1.0)
		{
			m_BG.StopScroll();

			m_isScrollStarted = false;
			m_scrollTimer = 0.0;


			// 次ステージ
			m_gauge.NextStage();

			CreateEnemies();
		}
	}


	m_BG.update();


	for (auto& enemy : m_enemies)
	{
		enemy.Update();
	}
}


void Game::draw() const
{
	m_BG.draw();

	for (const auto& enemy : m_enemies)
	{
		enemy.Draw();
	}

	m_player.Draw();
	// ゲージ描画
	m_gauge.draw();


	
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

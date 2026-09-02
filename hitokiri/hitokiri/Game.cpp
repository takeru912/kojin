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

	if (m_gauge.IsFailed())
	{
		changeScene(State::GameOver);
		return;
	}

	m_player.Update(m_BG.GetPlayGroundRect());

	bool allEnemiesDead = true;

	for (auto& enemy : m_enemies)
	{
		enemy.Update();

		if (!enemy.IsDead())
		{
			allEnemiesDead = false;
		}

		if (!enemy.IsDead() &&
			m_player.GetRect().intersects(enemy.GetRect()))
		{
			enemy.Dead();
		}
	}


	// 敵を全員倒したらスクロール開始
	if (!m_isScrollStarted && !m_enemies.empty() && allEnemiesDead)
	{
		m_BG.StartScroll();

		m_isScrollStarted = true;
		m_scrollDistance = 0.0;
	}


	// スクロール中
	if (m_isScrollStarted)
	{
		for (auto& enemy : m_enemies)
		{
			enemy.FadeOut();
		}

		m_scrollDistance += m_BG.GetScrollSpeed() * Scene::DeltaTime();

		if (m_scrollDistance >= Scene::Width())
		{
			m_BG.StopScroll();

			m_isScrollStarted = false;
			m_scrollDistance = 0.0;

			m_gauge.NextStage();
			if (m_gauge.GetStage() > 3)
			{
				m_isFinalRun = true;
				m_player.StartRunRight();
				return;
			}

			m_player.ResetPosition();

			CreateEnemies();
		}
	}


	m_BG.update();


	for (auto& enemy : m_enemies)
	{
		enemy.Update();
	}

	if (m_isFinalRun && m_player.IsOutOfScreen())
	{
		getData().score = m_gauge.GetTotalScore();

		changeScene(State::Result);
		return;
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
		spacing = 90;
		break;

	case 2:
		count = 10;
		spacing = 60;
		break;

	case 3:
		count = 15;
		spacing = 45;
		break;

	}

	double startX = Screen::WIDTH * 0.26;

	for (int i = 0; i < count; i++)
	{
		
		Vec2 pos
		{
			startX + i * spacing,
			m_BG.GetPlayGroundRect().y - 32
		};

		m_enemies.emplace_back(Vec2{pos});
	}
}

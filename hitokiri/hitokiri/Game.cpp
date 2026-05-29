#include "Game.h"

Game::Game(const InitData& init)
	:IScene{init}
{
}

void Game::update()
{
	m_gauge.update();
}

void Game::draw() const
{
	m_BG.draw();
	// ゲージ描画
	m_gauge.draw();
}


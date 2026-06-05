#include "Game.h"


Game::Game(const InitData& init)
	: IScene{ init }
	, m_player()
	, m_gauge(&m_player)
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


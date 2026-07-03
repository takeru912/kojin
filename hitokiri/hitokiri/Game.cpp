#include "Game.h"


Game::Game(const InitData& init)
	: IScene{ init }
	, m_player()
	, m_gauge()
{
}
void Game::update()
{

	m_gauge.update();
	m_player.Update();

}


void Game::draw() const
{
	m_BG.draw();
	// ゲージ描画
	m_gauge.draw();
	m_player.Draw();

}


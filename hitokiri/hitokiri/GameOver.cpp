#include "stdafx.h"
#include "GameOver.h"

GameOver::GameOver(const InitData& init)
	: IScene{ init }
{
}

void GameOver::update()
{
	if (KeySpace.down())
	{
		changeScene(State::Title);
	}
}

void GameOver::draw() const
{
	Scene::SetBackground(ColorF{ 0.1 });

	m_font(U"GAME OVER")
		.drawAt(Scene::Center(), Palette::White);

	m_smallFont(U"SPACEでタイトルへ戻る")
		.drawAt(Scene::Center().movedBy(0, 80), Palette::White);
}

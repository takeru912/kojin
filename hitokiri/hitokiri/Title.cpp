# include "Title.h"

Title::Title(const InitData& init)
	: IScene(init)
{
}

void Title::update()
{
	if (KeySpace.down())
	{
		changeScene(State::Game);
	}

	if (KeyEscape.down())
	{
		System::Exit();
	}

	count++;

	if (count >= 40)
	{
		count = 0;

		pat++;

		if (pat >= patMax)
		{
			pat = 0;
		}
	}


	if (KeyG.down())
	{
		changeScene(State::GameOver);
	}

}

void Title::draw() const
{
	bg.resized(Scene::Size()).draw();

	ground.resized(Scene::Size()).draw();

	int32 srcX = (pat % patMax) * FRAME_W;
	int32 srcY = 0;

	if (pat == 1)
	{
		srcY = patMax * FRAME_H;
	}

	if (pat == (patMax - 1))
	{
		srcX = (pat % 9) * FRAME_W;
		srcY = 7 * FRAME_H;
	}

	Rect srcRect{
		srcX,
		srcY,
		FRAME_W,
		FRAME_H
	};

	chara(srcRect).scaled(2.5).draw(m_pos);

	font(U"Push [SPACE] Key To Play")
		.draw(100, 400, Palette::White);
}

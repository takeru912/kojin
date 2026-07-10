# include "Common.h"
# include "Title.h"
# include "Game.h"
# include "Result.h"
#include "NameSpaceScreen.h"

void Main()
{
	Window::Resize(Screen::WIDTH,Screen::HEIGHT);

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 48, U"example/font/RocknRoll/RocknRollOne-Regular.ttf");
	FontAsset(U"TitleFont").setBufferThickness(4);

	FontAsset::Register(U"Bold", FontMethod::MSDF, 48, Typeface::Bold);

	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);
	manager.add<Result>(State::Result);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}

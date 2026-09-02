# include "Common.h"
# include "Title.h"
# include "Game.h"
# include "Result.h"
#include "GameOver.h"
#include "NameSpaceScreen.h"

void Main()
{
	Window::Resize(1280,720);
	Scene::SetResizeMode(ResizeMode::Keep);

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 48, U"example/font/RocknRoll/RocknRollOne-Regular.ttf");
	FontAsset(U"TitleFont").setBufferThickness(4);

	FontAsset::Register(U"Bold", FontMethod::MSDF, 48, Typeface::Bold);

	App manager;
	manager.add<Title>(State::Title);
	manager.add<Game>(State::Game);
	manager.add<Result>(State::Result);
	manager.add<GameOver>(State::GameOver);

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}

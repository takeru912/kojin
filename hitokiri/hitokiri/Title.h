#pragma once
# include <Siv3D.hpp>
# include "Common.h"
#include "NameSpaceScreen.h"

class Title : public App::Scene
{
private:

	Texture bg{ U"image/TitleBG.png" };
	Texture chara{ U"image/Chara.png" };
	Texture ground{ U"image/Ground.png" };

	Font font{ 40 };

	int32 pat = 0;
	int32 count = 0;

	static constexpr int32 patMax = 4;

	static constexpr int32 FRAME_W = 48;
	static constexpr int32 FRAME_H = 32;

	Vec2 m_pos{ 200,470 };

public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;
};

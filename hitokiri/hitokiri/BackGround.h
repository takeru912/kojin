# pragma once
# include "Common.h"

// ゲームシーン
class BackGround
{
public:

	BackGround();

	void update();

	void draw()const;
private:
	Texture bg{ U"image/BackGround.png" };
	Texture pg{ U"image/playground.png" };
};

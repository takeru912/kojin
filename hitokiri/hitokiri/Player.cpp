#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

void Player::Update()
{
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
}

void Player::Draw() const
{
	int32 srcX = (pat % patMax) * FRAME_W;
	int32 srcY = 0;

	switch (anime)
	{
	case 0:
		srcY = 0 * FRAME_H;
		break;
	case 1:
		srcY = 5 * FRAME_H;
		break;
	case 2:
		srcY = 6 * FRAME_H;
		break;
	case 3:
		srcY = 7 * FRAME_H;
		break;
	}

	srcX = pat * FRAME_W;

	Rect srcRect{
		srcX,
		srcY,
		FRAME_W,
		FRAME_H
	};

	chara(srcRect).scaled(2.5).draw(m_charaPos);
}

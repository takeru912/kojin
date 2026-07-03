#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

void Player::Update()
{

	if (m_gauge&& m_gauge->IsStageChanging())
	{
		switch (m_gauge->GetStage())
		{
		case 1:
			anime = 1;
			break;
		case 2:
			anime = 2;
			break;
		case 3:
			anime = 3;
			break;
		}
	}
	else
	{
		anime=0;
	}

	switch (anime)
	{
	case 0:
		patMax = 4;
		break;
	case 1:
		patMax = 9;
		break;
	case 2:
		patMax = 10;
		break;
	case 3:
		patMax = 15;
		break;
	}

	if (anime != oldAnime)
	{
		pat = 0;
		count = 0;
		m_animEnd = false;

		oldAnime = anime;
	}

	count++;

	if (count >= 40)
	{
		count = 0;

		if (anime == 0)
		{
			//通常アニメはループ
			pat++;

			if (pat >= patMax)
			{
				pat = 0;
			}
		}
		else
		{
			//クリアアニメは一回だけ
			if (pat < patMax - 1)
			{
				pat++;
			}
			else
			{
				m_animEnd = true;
			}
		}
	}

	if (anime == 0)
	{
		m_animEnd = false;
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
		srcY = 6 * FRAME_H;
		break;
	case 2:
		srcY = 7 * FRAME_H;
		break;
	case 3:
		srcY = 8 * FRAME_H;
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


void Player::SetGauge(Gauge* gauge)
{
	m_gauge = gauge;
}

bool Player::IsAnimEnd() const
{
	return m_animEnd;
}

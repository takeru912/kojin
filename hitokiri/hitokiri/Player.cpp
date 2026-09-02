#include "stdafx.h"
#include "Player.h"

RectF Player::GetRect() const
{
	return RectF{
		m_charaPos.x,
		m_charaPos.y,
		FRAME_W * 2.5,
		FRAME_H * 2.5
	};
}

Player::Player()
{
}

void Player::Update(const RectF& ground)
{
	if (m_gauge&& m_gauge->IsStageChanging()&& !m_isScrollStart)
	{
		m_isRunning = true;

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

	if (m_isRunning)
	{
		m_charaPos.x += m_speed * Scene::DeltaTime();
	}

	if (!m_isFinalRun && m_charaPos.x >= Scene::Width() * 0.8)
	{
		m_charaPos.x = Scene::Width() * 0.8;
		m_isRunning = false;
		m_isScrollStart = true;
	}

	switch (anime)
	{
	case 0:
		patMax = 4;
		animeSpeed = 40;
		break;
	case 1:
		patMax = 9;
		animeSpeed = 10;
		break;
	case 2:
		patMax = 10;
		animeSpeed = 10;
		break;
	case 3:
		patMax = 15;
		animeSpeed = 10;
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

	if (count >= animeSpeed)
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

	//地面判定
	RectF playerRect = GetRect();

	if (playerRect.intersects(ground))
	{
		m_charaPos.y = ground.y - playerRect.h;
	}

}

void Player::Draw() const
{

	int32 srcX = pat * FRAME_W;
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

void Player::ResetPosition()
{
	m_charaPos.x = 200;
	m_isRunning = false;
	m_isScrollStart = false;
}

void Player::StartRunRight()
{
	m_isFinalRun = true;
	m_isRunning = true;
	m_isScrollStart = false;
}

bool Player::IsOutOfScreen() const
{
	return m_charaPos.x > Scene::Width();
}


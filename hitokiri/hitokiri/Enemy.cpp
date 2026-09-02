#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
	:m_pos{0,0}
{
	m_type = Random(0, static_cast<int32>(m_enemies.size() - 1));
}

Enemy::Enemy(Vec2 pos)
	:m_pos(pos)
{
	m_type = Random(0, static_cast<int32>(m_enemies.size() - 1));

}

void Enemy::Update()
{
	if (m_timer.ms() >= 100)
	{
		m_frame++;

		if (!m_isDead)
		{
			if (m_frame >= m_enemies[m_type].idleframeCount)
			{
				m_frame = 0;
			}
		}
		else
		{
			if (m_frame >= m_enemies[m_type].deadframeCount)
			{
				m_frame = m_enemies[m_type].deadframeCount - 1;
			}
		}
		m_timer.restart();
	}
}

void Enemy::Draw()const
{
	const auto& enemy = m_enemies[m_type];

	const Texture& texture = m_isDead
		? enemy.deadTextures
		: enemy.idleTextures;

	int32 frameCount = m_isDead
		? enemy.deadframeCount
		: enemy.idleframeCount;

	int32 width = texture.width() / frameCount;
	int32 height = texture.height();

	texture(m_frame * width, 0, width, height)
		.mirrored()
		.drawAt(m_pos, ColorF{ 1.0, m_alpha });

}

void Enemy::Dead()
{
	
		m_isDead = true;
		m_frame = 0;
		m_timer.restart();
}

Vec2 Enemy::GetPos() const
{
	return m_pos;
}


RectF Enemy::GetRect() const
{
	const auto& enemy = m_enemies[m_type];

	const Texture& texture = m_isDead
		? enemy.deadTextures
		: enemy.idleTextures;

	int32 frameCount = m_isDead
		? enemy.deadframeCount
		: enemy.idleframeCount;

	int32 width = texture.width() / frameCount;
	int32 height = texture.height();

	return RectF{
		Arg::center(m_pos),
		width,
		height
	};
}

void Enemy::FadeOut()
{
	if (m_isDead)
	{
		m_alpha -= 1.5 * Scene::DeltaTime();

		if (m_alpha < 0.0)
		{
			m_alpha = 0.0;
		}
	}
}

#include "stdafx.h"
#include "Player.h"
#include"Gauge.h"

Player::Player()
{
}

void Player::Update()
{
}

void Player::Draw() const
{
}

void Player::MoveRight(double x)
{
	m_charaPos.x += x;
}

void Player::ResetPos()
{
	m_charaPos = Vec2{ 200,500 };
}

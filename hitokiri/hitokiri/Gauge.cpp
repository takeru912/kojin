#include "stdafx.h"
#include "Gauge.h"

Gauge::Gauge(Player* player)
	:m_player(player)
{

}

void Gauge::update()
{
	//stage変える演出
	if (m_stageChanging) {
		m_stageTimer += Scene::DeltaTime();

		if (m_stageTimer >= 1.5) {
			m_stageChanging = false;

			m_stage++;


			//stage3クリア後
			if (m_stage > 3) {
				return;
			}
			m_count = 0;
			successCount = 0;
		}
		return;
	}

	switch (m_stage) {
	case 1:
		m_maxCount = 3;
		successValue = 265;
		needSuccessCount = 2;
		break;

	case 2:
		m_maxCount = 5;
		successValue = 270;
		needSuccessCount = 3;
		break;
	case 3:
		m_maxCount = 7;
		successValue = 280;
		needSuccessCount = 5;
		break;
	}

	//SPACEを押した瞬間の値を記録
	if (KeySpace.down() && m_count < m_maxCount)
	{
		m_stopPower = m_power;
		m_isStop = true;

		if (m_stopPower >= 280)
		{
			successCount++;
			m_player->MoveRight(120);
		}
		else if (m_stopPower >= 270)
		{
			successCount++;
			m_player->MoveRight(80);
		}
		else if (m_stopPower >= 265)
		{
			successCount++;
			m_player->MoveRight(40);
		}

		m_count++;
	}

	if (m_count >= m_maxCount){
		//成功回数以上なら次のステージ
		if (successCount >= needSuccessCount) {
			m_stageChanging = true;
			m_stageTimer = 0.0;
		}
	}

	if (m_count < m_maxCount) {
		// ゲージ増減
		if (m_up)
		{
			m_power += Gaugespd * Scene::DeltaTime();

			if (m_power >= 300)
			{
				m_power = 300;
				m_up = false;
			}
		}
		else
		{
			m_power -= Gaugespd * Scene::DeltaTime();

			if (m_power <= 0)
			{
				m_power = 0;
				m_up = true;
			}
		}
	}
}

void Gauge::draw() const
{
	Scene::SetBackground(ColorF{ 0.1 });

	// 外枠
	RoundRect{ m_gaugePos, 320, 30, 8 }
	.draw(ColorF{ 0.2 });

	// 内側ゲージ
	RoundRect{ m_gaugePos + Vec2{10, 5}, m_power, 20, 6 }
	.draw(HSV{ 120 - (m_power / 300.0) * 120 });

	//記録位置表示
	if (m_isStop) {
		m_font(U"POWER : {}"_fmt(static_cast<int32>(m_stopPower)))
			.draw(Vec2{ 320,450 }, Palette::White);
	}
}





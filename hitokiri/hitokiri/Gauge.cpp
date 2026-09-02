#include "stdafx.h"
#include "Gauge.h"

Gauge::Gauge()
{

}

void Gauge::update()
{
	switch (m_stage) {
	case 1:
		m_maxCount = 3;
		successValue = 265;
		needSuccessCount = 2;
		gaugespdratio = 1.0;
		break;

	case 2:
		m_maxCount = 5;
		successValue = 270;
		needSuccessCount = 3;
		gaugespdratio = 1.5;
		break;
	case 3:
		m_maxCount = 7;
		successValue = 280;
		needSuccessCount = 5;
		gaugespdratio = 2.0;
		break;
	}

	//SPACEを押した瞬間の値を記録
	if (KeySpace.down() && m_count < m_maxCount)
	{
		m_stopPower = m_power;
		m_totalScore += static_cast<int32>(m_stopPower);
		m_isStop = true;

		if (m_stopPower >= 280)
		{
			successCount++;;
		}
		else if (m_stopPower >= 270)
		{
			successCount++;;
		}
		else if (m_stopPower >= 265)
		{
			successCount++;;
		}

		m_count++;
	}

	if (m_count >= m_maxCount){
		//成功回数以上なら次のステージ
		if (successCount >= needSuccessCount) {
			m_stageChanging = true;
		}
	}

	if (m_count < m_maxCount) {
		// ゲージ増減
		if (m_up)
		{
			m_power += Gaugespd * gaugespdratio * Scene::DeltaTime();

			if (m_power >= 300)
			{
				m_power = 300;
				m_up = false;
			}
		}
		else
		{
			m_power -= Gaugespd * gaugespdratio * Scene::DeltaTime();

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
	for (int32 i = 0; i < 30; ++i)
	{
		if (i < static_cast<int32>(m_power / 10))
		{
			RectF{
				m_gaugePos.x + 10 + i * 10,
				m_gaugePos.y + 5,
				8,
				20
			}
			.draw(HSV{ 120 - (m_power / 300.0) * 120 });
		}
	}

	//記録位置表示
	if (m_isStop)
	{
		m_font(U"POWER : {}"_fmt(static_cast<int32>(m_stopPower)))
			.draw(m_gaugePos + Vec2{ 20, -45 }, Palette::White);
	}
}

int Gauge::GetStage() const
{
	return m_stage;
}

bool Gauge::IsStageChanging() const
{
     	return m_stageChanging;
}

bool Gauge::IsFailed() const
{
	return (m_count >= m_maxCount &&
			successCount < needSuccessCount);
}

void Gauge::NextStage()
{
	m_stageChanging = false;

	m_stage++;

	if (m_stage > 3)
	{
		return;
	}

	m_count = 0;
	successCount = 0;
}

int32 Gauge::GetTotalScore() const
{
	return m_totalScore;
}

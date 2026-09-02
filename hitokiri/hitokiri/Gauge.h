# pragma once
# include "Common.h"


// ゲームシーン
class Gauge 
{
public:

	Gauge();

	void update() ;

	void draw()const ;

	int GetStage() const;
	bool IsStageChanging() const;
	bool IsFailed() const;

	int32 GetTotalScore() const;

	void NextStage();
private:

	// ゲージの位置
	Vec2 m_gaugePos{ 450, 300 };

	// ゲージの現在値
	double m_power = 0.0;

	// 増加方向
	bool m_up = true;

	double m_stopPower = 0.0;
	int32 m_totalScore = 0;

	bool m_isStop = false;

	bool m_stageChanging = false;
	const double STAGE_CHANGE_TIME = 1.5;


	Font m_font{ 30 };

	int Gaugespd = 500;

	int m_stage = 1;
	int m_maxCount = 3;
	int m_count = 0;

	int successCount = 0;
	int successValue = 0;
	int needSuccessCount = 0;
	int gaugespdratio = 0;

};

# pragma once
# include "Common.h"
#include"Player.h"

// ゲームシーン
class Gauge 
{
public:

	Gauge(Player* player);

	void update() ;

	void draw()const ;
private:

	// ゲージの位置
	Vec2 m_gaugePos{ 250, 500 };

	// ゲージの現在値
	double m_power = 0.0;

	// 増加方向
	bool m_up = true;

	double m_stopPower = 0.0;

	bool m_isStop = false;

	bool m_stageChanging = false;
	double m_stageTimer = 0.0;
	const double STAGE_CHANGE_TIME = 1.5;


	Font m_font{ 30 };

	int Gaugespd = 500;

	int m_stage = 1;
	int m_maxCount = 3;
	int m_count = 0;

	int successCount = 0;
	int successValue = 0;
	int needSuccessCount = 0;


	Player* m_player = nullptr;

};

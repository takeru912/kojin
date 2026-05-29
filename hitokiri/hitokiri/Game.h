#pragma once
#include "Common.h"
#include "Gauge.h"
#include"BackGround.h"

// ゲームシーン
 class Game : public App::Scene
 {
 public:
	 Game(const InitData& init);
	 void update() override;
	 void draw() const override;
 private:
	 Gauge m_gauge;
	 BackGround m_BG;
 };

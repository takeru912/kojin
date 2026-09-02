#pragma once
#include "Common.h"
#include "Gauge.h"
#include"BackGround.h"
#include"Player.h"
#include "Enemy.h"

// ゲームシーン
 class Game : public App::Scene
 {
 public:
	 Game(const InitData& init);
	 void update() override;
	 void draw() const override;
	 
 private:
	 Player m_player;
	 Gauge m_gauge;
     BackGround m_BG;
	 Enemy m_enemy;
	 double spacing;

     double m_clearTimer = 0.0;
     bool m_waitNextStage = false;

     Array<Enemy> m_enemies;
	 void CreateEnemies();

	 bool m_isScrollStarted = false;
	 double m_scrollDistance = 0.0;
	 
	 bool m_isFinalRun = false;
 };

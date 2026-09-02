# pragma once
# include "Common.h"

// ランキングシーン
class Result : public App::Scene
{
public:

	Result(const InitData& init);

	void update() override;

	void draw() const override;

private:

	static constexpr int32 RankingCount = 5;
	int32 m_score = 0;

	int32 m_rank = -1;
};

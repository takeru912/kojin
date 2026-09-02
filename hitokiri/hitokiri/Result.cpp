# include "Result.h"

Result::Result(const InitData& init)
	: IScene{ init }
{
	auto& data = getData();

	// 今回のスコアを保存
	m_score = data.score;

	if (data.score)
	{
		// ランキングを再構成
		data.highScores << data.score;
		data.highScores.rsort();
		data.highScores.resize(RankingCount);

		// ランクインしていたら m_rank に順位をセット
		for (int32 i = 0; i < RankingCount; ++i)
		{
			if (data.highScores[i] == data.score)
			{
				m_rank = i;
				break;
			}
		}

		// 共有データのスコアをリセット
		data.score = 0;
	}
}

void Result::update()
{
	if (KeySpace.down())
	{
		// タイトルシーンへ
		changeScene(State::Title);
	}
}

void Result::draw() const
{
	Scene::SetBackground(ColorF{ 0.4, 0.6, 0.9 });

	const Font& boldFont = FontAsset(U"Bold");
	const auto& data = getData();

	// 今回のスコア
	boldFont(U"SCORE : {}"_fmt(m_score))
		.drawAt(400, 50, Palette::White);

	// ランキングタイトル
	boldFont(U"RANKING")
		.drawAt(400, 110, Palette::White);

	// ランキングを表示
	for (int32 i = 0; i < RankingCount; ++i)
	{
		const RectF rect{ 100, (160 + i * 80), 600, 70 };

		rect.draw(ColorF{ 1.0, (1.0 - i * 0.2) });

		boldFont(U"{}位   {}"_fmt(i + 1, data.highScores[i]))
			.drawAt(rect.center(), ColorF{ 0.1 });

		// 今回のスコアがランクインしていたら
		if (i == m_rank)
		{
			rect.drawFrame(2, 10, ColorF{ 1.0, 0.8, 0.2 });
		}
	}
}

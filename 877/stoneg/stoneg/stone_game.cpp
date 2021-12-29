#include "stone_game.h"
#include <vector>
S_GAME::S_GAME() {}

S_GAME::~S_GAME() {}

int S_GAME::judge_score(int piles[], int n)
{
	// 初始化 dp 数组
	std::vector<std::vector<Pair>> dp(n, std::vector<Pair>(n, Pair(0, 0)));

	//init state:
	for (int i = 0; i < n; i++)
	{
		dp[i][i].fir = piles[i];
		dp[i][i].sec = 0;
	}
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i+1; j < n; j++)
		{
			int right = dp[i][j - 1].sec + piles[j];
			int left = dp[i + 1][j].sec + piles[i];
			if (left > right)
			{
				dp[i][j].fir = left;
				dp[i][j].sec = dp[i + 1][j].fir;
			}
			else
			{
				dp[i][j].fir = right;
				dp[i][j].sec = dp[i][j - 1].fir;
			}
		}
	}
	Pair res = dp[0][n - 1];
	return res.fir - res.sec;
}
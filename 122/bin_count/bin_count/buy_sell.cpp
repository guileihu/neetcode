#include "buy_sell.h"
#include <algorithm>
#include <vector>

BUY_SELL::BUY_SELL() {
}
BUY_SELL::~BUY_SELL() {}

int BUY_SELL::dp_count(int prices[], int n, int k)
{
	//malloc dp array
	std::vector<std::vector<Pair>> dp(n, std::vector<Pair>(k + 1, Pair(0, 0)));
    


	//init state
	for (int i = 0; i < k + 1; i++)
	{
		dp[0][i].hold = -prices[0];
		dp[0][i].free=
	}

	//state transform
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			dp[i][j].hold = std::max(dp[i - 1][j - 1].free - prices[i], dp[i - 1][j].hold);
			dp[i][j].free = std::max(dp[i - 1][j].hold + prices[i], dp[i - 1][j].free);
		}
	}
	//return
	return dp[n - 1][k - 1].free;
}

int BUY_SELL::decide_bs(int prices[], int n)
{
	int gain = dp(0, prices, 0, 0);
}
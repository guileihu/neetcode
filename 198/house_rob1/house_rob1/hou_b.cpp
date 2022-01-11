#include "hou_b.h"
#include <vector>
#include <algorithm>

HOUSE_ROB::HOUSE_ROB() {}
HOUSE_ROB::~HOUSE_ROB() {}

int HOUSE_ROB::robber(int arr[], int num)
{
	std::vector<Pair> dp = std::vector<Pair>(num, Pair());
	dp[0].n_rob = 0;
	dp[0].rob = arr[0];
	for (int i = 1; i < num; i++)
	{
		dp[i].n_rob = std::max(dp[i - 1].n_rob,dp[i - 1].rob);
		dp[i].rob = dp[i - 1].n_rob + arr[i];
	}
	return std::max(dp[num - 1].n_rob, dp[num - 1].rob);
}
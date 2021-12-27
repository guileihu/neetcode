#include "tri.h"
#include <climits>
#include <vector>
#include <algorithm>

TRIVA::TRIVA() {}
TRIVA::~TRIVA() {}

int TRIVA::calcu_trive(int n, int flights[][LEN],int nums, int src, int dst, int k)
{
	std::vector<std::vector<int>> value(n, std::vector<int>(n, INT_MAX));
	std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n, INT_MAX));
	for (int i = 0; i < nums; i++)
		value[flights[i][0]][flights[i][1]] = flights[i][2];
	for (int j = 0; j < n; j++)
		dp[0][j] = value[0][j];
	
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if (dp[i - 1][l] < INT_MAX && value[l][j] < INT_MAX)
					dp[i][j] = fmin(dp[i][j], dp[i - 1][l] + value[l][j]);
			}
		}
	}
	int min_value = INT_MAX;
	for (int j = 0; j < n; j++)
	{
		min_value = fmin(min_value, dp[k][j]);
	}
	return min_value;
}
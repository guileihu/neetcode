#include "minp.h"
#include <vector>
#include <algorithm>

MIN_PATH::MIN_PATH() {}
MIN_PATH::~MIN_PATH() {}
int MIN_PATH::min_value_path(int arr[][ROOT_LEN], int rows)
{
	std::vector<std::vector<int>> dp(rows, std::vector<int>(ROOT_LEN, 0));
	dp[0][0] = arr[0][0];
	for (int j = 1; j < ROOT_LEN; j++)
	{
		dp[0][j] = dp[0][j - 1] + arr[0][j];
	}
	for (int j = 1; j < rows; j++)
	{
		dp[j][0] = dp[j-1][0] + arr[j][0];
	}
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < ROOT_LEN; j++)
		{
			dp[i][j] = fmin(dp[i][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}
	return dp[rows-1][ROOT_LEN-1];
}
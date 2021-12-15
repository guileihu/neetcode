#include "min_value.h"
#include <algorithm>
MIN_VALUE::MIN_VALUE() {}
MIN_VALUE::~MIN_VALUE() {}

int MIN_VALUE::min_array(std::vector<int> nums)
{
	int min_num = nums[0];
	for (int i = 0; i < COLS_NUM; i++)
	{
		min_num = fmin(min_num, nums[i]);
	}
	return min_num;
}

int MIN_VALUE::min_value_count(int nums[][COLS_NUM], int depth)
{
	std::vector<int> dp(COLS_NUM, 0);
	
	for (int i = 0; i < depth; i++)
	{
		int min_value[COLS_NUM] = { 0,0,0 };
		for (int j = 0; j < COLS_NUM; j++)
		{
			int min_v = 0;
			if (j - 1 >= 0)
			{
				min_v = fmin(dp[j - 1] + nums[i][j], dp[j] + nums[i][j]);
				if (j + 1 < COLS_NUM)
				{
					min_v = fmin(min_v, dp[j + 1] + nums[i][j]);
				}
			}
			else
			{
				if (j + 1 < COLS_NUM)
					min_v = fmin(dp[j + 1] + nums[i][j], dp[j] + nums[i][j]);
				else
					min_v = dp[j] + nums[i][j];
			}
			min_value[j] = min_v;
		}
		for (int i = 0; i < COLS_NUM; i++)
		{
			dp[i] = min_value[i];
		}
	}

	return min_array(dp);
}
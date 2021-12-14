#include "max_v.h"
#include <vector>
#include <algorithm>
ARRAY_MAX::ARRAY_MAX() {}

ARRAY_MAX::~ARRAY_MAX() {}

int ARRAY_MAX::count_max(int nums[], int len)
{
	if (len <= 0)
		return -1;
	else if (len == 1)
		return nums[0];
	std::vector<int> dp(len, 0);
	dp[0] = nums[0];
	int max_num = dp[0];
	for (int i = 1; i < len; i++)
	{
		dp[i] = fmax(dp[i - 1] + nums[i], nums[i]);
		max_num = fmax(max_num, dp[i]);
	}
	return max_num;
}
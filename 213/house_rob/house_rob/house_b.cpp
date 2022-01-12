#include "House_b.h"
#include <vector>
#include <algorithm>

HOUSE_ROB::HOUSE_ROB() {}
HOUSE_ROB::~HOUSE_ROB() {}

int HOUSE_ROB::house_rob(int arr[], int nums)
{
	std::vector<Pair> dp = std::vector<Pair>(nums, Pair(0, 0));
	int max_value = 0;
	//rob the first house
	dp[0].rob = arr[0];
	dp[1].n_rob = dp[0].rob;
	dp[2].rob = dp[1].n_rob + arr[2];
	dp[2].n_rob = dp[1].n_rob;
	if (nums < 3)
	{
		printf("not enough house\n");
		return -1;
	}
	else if (nums == 3)
	{
		if (dp[2].n_rob > max_value)
			max_value = dp[2].n_rob;
	}	
	else
	{
		for (int i = 3; i < nums; i++)
		{
			dp[i].n_rob = std::max(dp[i - 1].n_rob, dp[i - 1].rob);
			dp[i].rob = dp[i - 1].n_rob + arr[i];
		}
		if (dp[nums - 1].n_rob > max_value)
			max_value = dp[nums - 1].n_rob;
	}
	//not rob the first house
	dp[0].n_rob = 0;
	dp[1].n_rob = dp[0].n_rob;
	dp[1].rob = dp[0].n_rob + arr[1];
	if (nums < 3)
	{
		printf("not enough house\n");
		return -1;
	}
	else
	{
		for (int i = 2; i < nums; i++)
		{
			dp[i].n_rob = std::max(dp[i - 1].n_rob, dp[i - 1].rob);
			dp[i].rob = dp[i - 1].n_rob + arr[i];
		}
		if (std::max(dp[nums - 1].n_rob, dp[nums - 1].rob) > max_value)
			max_value = std::max(dp[nums - 1].n_rob, dp[nums - 1].rob);
	}
	return max_value;
}
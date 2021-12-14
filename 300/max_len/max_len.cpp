#include "max_len.h"
#include <string.h>
#include <algorithm>

MAX_LEN::MAX_LEN(int num)
{
	dp = new int[num + 1];
	memset(dp, 0, sizeof(int)*(num + 1));
}

MAX_LEN::~MAX_LEN()
{
	delete(dp);
}

int MAX_LEN::find_max_len(int array[], int len)
{
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= len; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (array[i - 1] > array[j - 1])
			{
				dp[i] = std::max(dp[i], dp[j] + 1);
			}
			else
			{
				dp[i]= std::max(dp[i], dp[j]);
			}
		}
	}
	return dp[len];
}
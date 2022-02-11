#include "M_reverse.h"
#include <vector>
#include <algorithm>

MAX_REVE::MAX_REVE(){}
MAX_REVE::~MAX_REVE() {}

int MAX_REVE::count_max(std::string str)
{
	int str_len = str.length();
	if (str_len < 2)
		return 0;

	int res = 0;
	for (int i = 1; i < str_len; i++)
	{
		std::string str1 = str.substr(0, i);
		std::string str2 = str.substr(i);
		std::reverse(str2.begin(), str2.end());
		int max_match = same_sub_str(str1, str2);
		if (max_match > res)
			res = max_match;
	}
	return res;
}

int MAX_REVE::same_sub_str(std::string str1, std::string str2)
{
	int n1 = str1.length();
	int n2 = str2.length();
	std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j - 1] + 2);
			}
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	//处理回文串为奇数的情况
	dp[n1][n2] = std::max(dp[n1][n2], dp[n1][n2 - 1] + 1);
	return dp[n1][n2];
}
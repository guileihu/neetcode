#include "matchp.h"
#include <vector>

MATCH::MATCH() {}
MATCH::~MATCH() {}

bool MATCH::ismatch(std::string str1, std::string str2)
{
	int strlen1 = strlen(str1.c_str());
	int strlen2 = strlen(str2.c_str());

	std::vector<std::vector<bool>> dp(strlen1, std::vector<bool>(strlen2, false));

	if (str2[0] == str1[0] || str1[0] == '.')
		dp[0][0] = true;
	else
		return false;
	for (int i = 0; i < strlen1; i++)
	{
		for (int j = 0; j < strlen2; j++)
		{
			if (i == 0 || j == 0)
				continue;
			if (str1[i] == str2[j] || str1[i] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else if (str1[i] == '*')
			{
				for (int k = j; k >= 0; k--)
				{
					if (str2[k] == str1[i - 1])
						dp[i][j] = dp[i][j] || dp[i - 1][k];
					else
						break;
				}
			}			
		}
	}
	return dp[strlen1 - 1][strlen2 - 1];
}
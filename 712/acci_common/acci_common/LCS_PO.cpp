#include "LCS_PRO.h"
#include <vector>
#include <algorithm>

int LCS::calculate_lcs(std::string str1, std::string str2)
{
	int len1 = strlen(str1.c_str());
	int len2 = strlen(str2.c_str());
	//std::vector<std::vector<int>> dp(len1+1, std::vector<int>(len2+1,0));
	std::vector<std::vector<std::string>> dp_s(len1+1, std::vector<std::string>(len2 + 1, ""));
	//init first row and first col
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				dp_s[i + 1][j + 1] = dp_s[i][j] + str1[i];
			}			
			else
			{
				dp_s[i + 1][j + 1] = dp_s[i][j + 1];
			}				
			//dp[i + 1][j + 1] = fmax(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	return 0;
}

LCS::LCS() {}
LCS::~LCS() {}
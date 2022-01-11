#include "key_c.h"
#include <algorithm>

KEY_C::KEY_C(int num) {
	this->n = num;
	//std::vector<std::vector<Pair>> dp(n, std::vector<Pair>(n, Pair(0, 0)));
	//info = dp;
}
KEY_C::~KEY_C() {}

int KEY_C::dp(int n, int nums, int copy)
{
	if (n <= 0)
		return nums;
	int max_num = 0;
	if (n >= 2)
	{
		int max_num1 = dp(n - 1, nums + 1, copy);
		int max_num2 = dp(n - 2, nums, nums);
		int max_num3 = dp(n - 1,nums + copy, copy);
		max_num = fmax(max_num1, max_num2);
		max_num = fmax(max_num, max_num3);
	}
	else
	{
		int max_num1 = dp(n - 1, nums + 1, copy);
		int max_num3 = dp(n - 1, nums + copy, copy);
		max_num = fmax(max_num1, max_num3);
		//max_num = fmax(max_num, dp(n - 1, this->nums + this->copy, this->copy));
	}
	
	return max_num;
}

int KEY_C::key_cal()
{
	int num = dp(this->n, 0, 0);
	//Pair[][] info = new Pair[n][n];
	return num;
}
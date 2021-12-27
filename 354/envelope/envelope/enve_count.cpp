#include "enve_count.h"
#include <vector>
#include <algorithm>

ENVE_C::~ENVE_C() {}

ENVE_C::ENVE_C(int nums): MAX_LEN(nums) {
}

bool ENVE_C::less_judge(int p1[2], int p2[2])
{
	if (p1[0] <= p2[0])
	{
		if (p1[1] <= p2[0])
			return true;
	}
	return false;
}

void ENVE_C::swap(int p1[2], int p2[2])
{
	int tmp[2] = { 0 };
	tmp[0] = p1[0];
	tmp[1] = p1[1];
	p1[0] = p2[0];
	p1[1] = p2[1];
	p2[0] = tmp[0];
	p2[1] = tmp[1];	
}

void ENVE_C::quick_sort(int env[][2], int sta, int en)
{
	int record_sta = sta;
	int record_en = en;
	if (sta >= en)
		return;
	int sold[2] = {};
	sold[0] = env[sta][0];
	sold[1] = env[sta][1];
	while (sta < en)
	{
		while (less_judge(sold, env[en]))
		{ 
			en--;
		}
		swap(env[en], sold);
		while (less_judge(env[sta], sold))
		{
			sta++;
		}
		swap(env[sta], sold);
	}
	quick_sort(env, record_sta, sta-1);
	quick_sort(env, sta + 1, record_en);
}

int ENVE_C::env_count(int env[][2], int nums)
{
	quick_sort(env, 0, 3);

	std::vector<int> arr(nums, 0);
	for (int i = 0; i < nums; i++)
	{
		arr[i] = env[i][1];
	}
	//calculate count
	//
	int max_len = MAX_LEN::find_max_len(arr, nums);
	return max_len;
}

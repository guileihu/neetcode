#include "eq_sub.h"

SUBSET::SUBSET() {}
SUBSET::~SUBSET() {}

void SUBSET::insert(std::vector<int>& value, std::vector<int>& nums, int ae)
{
	int i = 0;
	for (i = 0; i < value.size(); i++)
	{
		if (value[i] == ae)
		{
			nums[i]++;
			break;
		}
			
	}
	if (i == value.size())
	{
		value.push_back(ae);
		nums.push_back(1);
	}
}

bool SUBSET::make_up(std::vector<int> value, std::vector<int> nums, int sub_v)
{
	if (sub_v == 0)
		return true;
	else
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (nums[i] >= 1)
			{
				nums[i]--;
				if (make_up(value, nums, sub_v - value[i]))
					return true;
			}			
		}
	}
	return false;
}

bool SUBSET::split(int arr[], int nums)
{
	std::vector<int> value;
	std::vector<int> v_nums;
	int all_num = 0;
	for (int i = 0; i < nums; i++)
	{
		int ae = arr[i];
		all_num += ae;
		insert(value, v_nums, ae);
	}
	if (all_num % 2 != 0)
		return false;
	else
		return make_up(value, v_nums, all_num / 2);
}
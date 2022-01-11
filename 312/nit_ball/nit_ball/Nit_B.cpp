#include "Nit_B.h"

N_BALL::N_BALL() {}
N_BALL::~N_BALL() {}

bool N_BALL::equal_arr(Pair tmp1, Pair tmp2)
{
	if (tmp1.value != tmp2.value)
		return false;
	else
	{
		for (int i = 0; i < tmp1.arr.size(); i++)
		{
			if (tmp1.arr[i] != tmp2.arr[i])
				return false;
		}
	}
	return true;
}

bool N_BALL::judge_in_arr(Pair tmp1)
{
	for (int i = 0; i < ball_array.size(); i++)
	{
		if (equal_arr(tmp1, ball_array[i]))
		{
			tmp1.value = ball_array[i].value;
			return true;
		}
			
	}
	return false;
}

int N_BALL::dp(std::vector<int> arr, int num)
{
	Pair tmp;
	tmp.arr = arr;
	int tmp_value = 0;	
	int i = 0;
	for (i = 0; i < num; i++)
	{	
		int c1, c2;
		if (i - 1 < 0)
			c1 = 1;
		else
			c1 = arr[i - 1];
		if (i + 1 == num)
			c2 = 1;
		else
			c2 = arr[i + 1];
		int get_value = arr[i] * c1*c2;
		Pair tmp1;
		tmp1.arr = arr;
		tmp1.arr.erase(tmp1.arr.begin() + i);
		if (tmp1.arr.size() == 0)
		{
			tmp_value = get_value;
		}
		else
		{
			int j = 0;
			for (j=0; j < ball_array.size(); j++)
			{
				if (judge_in_arr(tmp1))//有记录
				{
					break;
				}
			}
			if (j == ball_array.size())//没有记录
			{
				tmp1.value=dp(tmp1.arr, tmp1.arr.size());
			}
			if (tmp1.value + get_value > tmp_value)
				tmp_value = tmp1.value + get_value;
		}
		
	}
	
	
	tmp.value = tmp_value;
	ball_array.push_back(tmp);
	return tmp_value;
}

int N_BALL::needdle_ball(int arr[], int num)
{
	std::vector<int> vec_arr;
	for (int i = 0; i < num; i++)
		vec_arr.push_back(arr[i]);
	//Pair tmp(0);
	dp(vec_arr, num);
	int tmp_value = 0;
	return ball_array[ball_array.size() - 1].value;
}
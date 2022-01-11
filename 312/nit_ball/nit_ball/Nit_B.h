#ifndef _H_N_BALL_H_
#define _H_N_BALL_H_
#include <vector>

class Pair {
public:
	int value;
	std::vector<int> arr;
	/*Pair(int num)
	{
		value = num;
		while (value > 0)
		{
			arr.push_back(0);
			value--;
		}
	}*/
};

class N_BALL
{
public:
	N_BALL();
	~N_BALL();
	int needdle_ball(int arr[], int num);
private:
	int dp(std::vector<int> vec_arr, int num);
	bool equal_arr(Pair tmp1, Pair tmp2);
	std::vector<Pair> ball_array;
	bool judge_in_arr(Pair tmp1);
};

#endif

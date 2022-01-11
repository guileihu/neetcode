#ifndef _H_KEY_C_H_
#define _H_KEY_C_H_

#include <vector>

class Pair {
public:
	int val;
	int copy;
	Pair(int v, int c)
	{
		this->val = v;
		this->copy = c;
	}
};

class KEY_C
{
public:
	KEY_C(int n);
	~KEY_C();
	int key_cal();
	int n;
	//std::vector<std::vector<Pair>> info;
private:
	int dp(int n, int nums, int copy);
	int copy;
	int nums;
};

#endif

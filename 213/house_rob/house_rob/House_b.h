#ifndef _H_HOUSE_ROB_H_
#define _H_HOUSE_ROB_H_

class Pair {
public:
	int rob;
	int n_rob;
	Pair(int x, int y)
	{
		rob = x;
		n_rob = y;
	}
	Pair(){}
};

class HOUSE_ROB
{
public:
	HOUSE_ROB();
	~HOUSE_ROB();
	int house_rob(int arr[], int nums);
};

#endif 


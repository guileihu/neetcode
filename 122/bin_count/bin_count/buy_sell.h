#ifndef _H_BUY_SELL_H_
#define _H_BUY_SELL_H_

class Pair {
public:	
	Pair(int buy, int sell)
	{
		this->hold = buy;
		this->free = sell;
	}
	int hold;
	int free;
};

class BUY_SELL
{
public:
	BUY_SELL();
	~BUY_SELL();

	int decide_bs(int prices[], int n);

private:
	int dp_count(int prices[], int n, int k);
	int dp_n;
};

#endif


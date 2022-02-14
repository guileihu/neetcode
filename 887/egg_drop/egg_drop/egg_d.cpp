#include "egg_d.h"
#include "algorithm"

EGG_DOP::EGG_DOP() {};
EGG_DOP::~EGG_DOP() {};

bool EGG_DOP::search(int n, int k, int& v)
{
	v = -1;
	for (int i = 0; i < memo.size(); i++)
	{
		Trip temp = memo[i];
		if (temp.k == k && temp.n == n)
		{
			v = temp.v;
			return true;
		}
	}
	return false;
}

int EGG_DOP::drop_count(int K, int N)
{
	if (N == 0)
		return 0;
	if (K == 1)
		return N;
	//exist in memory?
	int v;
	bool sig = search(N, K, v);
	if (sig)
		return v;

	int res = INT32_MAX;
	for (int i = 1; i < N+1; i++)
	{	
		//choose i:
		res = std::min(res, std::max(drop_count(K - 1, i - 1), drop_count(K, N - i)) + 1);
	}
	Trip temp = Trip(K, N, res);
	memo.push_back(temp);
	return res;
}
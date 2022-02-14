#ifndef _H_EGG_DOP_H_
#define _H_EGG_DOP_H_

#include <vector>

class Trip {
public:
	Trip(int k, int n, int v)
	{
		this->k = k;
		this->n = n;
		this->v = v;
	}
	int n;
	int k;
	int v;
};

class EGG_DOP {
public:
	EGG_DOP();
	~EGG_DOP();
	int drop_count(int N, int K);

private:
	std::vector<Trip> memo;
	bool search(int n, int k, int& v);
};

#endif

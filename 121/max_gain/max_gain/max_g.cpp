#include "max_g.h"
#include <vector>
#include <algorithm>

MAX_G::MAX_G() {}
MAX_G::~MAX_G() {}

int MAX_G::count_max(int arr[6], int n)
{
	std::vector<int> dp_min(n, arr[0]);
	std::vector<int> dp_max(n, arr[n - 1]);
	//get dp_min
	for (int i = 1; i < n; i++)
		dp_min[i] = std::min(dp_min[i - 1], arr[i]);
	
	for (int i = n - 2; i >= 0; i--)
		dp_max[i] = std::max(dp_max[i + 1], arr[i]);

	int max_g = 0;
	for (int i = 0; i < n; i++)
		max_g = std::max(max_g, dp_max[i] - dp_min[i]);
	return max_g;
}
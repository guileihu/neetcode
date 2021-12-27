#pragma once
#include <vector>
class MAX_LEN {
public:	
	MAX_LEN(int len);
	~MAX_LEN();

	int find_max_len(int array[], int len);
	int find_max_len(std::vector<int> array, int len);
private:
	int* dp;
};
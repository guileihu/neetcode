#pragma once
class MAX_LEN {
public:	
	MAX_LEN(int len);
	~MAX_LEN();

	int find_max_len(int array[], int len);
private:
	int* dp;
};
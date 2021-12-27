#ifndef _H_ENVE_H_
#define _H_ENVE_H_

#include "max_len.h"

class ENVE_C:MAX_LEN
{
public:
	ENVE_C(int nums);
	~ENVE_C();
	int env_count(int env[][2], int nums);
	void quick_sort(int env[][2], int i, int j);
	bool less_judge(int p1[2], int p2[2]);
	void swap(int p1[2], int p2[2]);
};


#endif

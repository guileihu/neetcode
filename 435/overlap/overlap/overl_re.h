#ifndef _H_OVERLAP_H_
#define _H_OVERLAP_H_

#define LEN 2

class OVERLAP
{
public:
	OVERLAP();
	~OVERLAP();
	int delete_region(int regions[][LEN] , int nums);
private:
	void quick_sort(int regions[][LEN], int start, int end);
	int partition(int regions[][LEN], int start, int end);
};

#endif

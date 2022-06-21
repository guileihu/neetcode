#ifndef _H_MEET_ARR_H_
#define _H_MEET_ARR_H_
#include <vector>

class Pair {
	Pair(int value, int count)
	{
		this->value = value;
		this->count = count;
	}
private:
	int value;
	int count;
};

class MEET_ARR
{
public:
	MEET_ARR();
	~MEET_ARR();
	//violent
	int meet_calcu(int meets[][2], int nums);
	//elegent
	int meet_ele(int meets[][2], int nums);

private:
	void quick_sort(int meets[][2], int start, int end);
	void quick_sort(std::vector<std::vector<int>>& meets, int start, int end);
	int partition(int meets[][2], int start, int end);
	int partition(std::vector<std::vector<int>>& meets, int start, int end);
	//NODE* malloc_list(int meets[][2], int nums);
	//void insert_node(NODE* head, int value, int count);
};




#endif // !_H_MEET_ARR_H_


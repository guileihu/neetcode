#ifndef _H_L_NODE_H_
#define _H_L_NODE_H_
#include <vector>

class NODE
{
public:
	NODE(int value);
	int value;
	NODE* next;
};

class CAT_K_LIST
{
public:
	CAT_K_LIST(NODE* list[], int num);
	void run_module(NODE* head);
private:
	int num;
	std::vector<NODE*> list_array;
	void sort_list_array(NODE* list[], int num);
	void quick_sort(NODE* list[], int first, int sec);
	void insert_brother(std::vector<NODE*> list, NODE* bro, int num);
};

#endif

#include "k_node_cat.h"
#include <stdlib.h>

NODE::NODE(int value)
{
	this->value = value;
	this->next = NULL;
}

void CAT_K_LIST::quick_sort(NODE* list[], int firs, int se)
{
	if (firs >= se)
	{
		return;
	}
	int first = firs;
	int sec = se;
	NODE* soldier = list[first];
	while (first < sec)
	{
		while (list[sec]->value > soldier->value && first < sec)
		{
			sec--;
		}
		list[first] = list[sec];
		while (list[first]->value < soldier->value && first < sec)
		{
			first++;
		}
		list[sec] = list[first];
	}
	list[first] = soldier;
	quick_sort(list, firs, first - 1);
	quick_sort(list, first + 1, se);
}

void CAT_K_LIST::sort_list_array(NODE* list[], int num)
{
	if (num > 2)
		quick_sort(list, 0, num - 1);
}

CAT_K_LIST::CAT_K_LIST(NODE* list[], int num)
{
	sort_list_array(list, num);
	this->num = num;
	for (int i = 0;i < num; i++)
	{
		list_array.push_back(list[i]);
	}
}

void CAT_K_LIST::insert_brother(std::vector<NODE*> list, NODE* bro, int num)
{
	if (bro->value <= list[0]->value)
		list.insert(list.begin(), bro);
	else if (bro->value>=list[num-1]->value)
		list.insert(list.end(), bro);
	else
	{
		int first = 0;
		int en = num - 1;
		while(en-first>2)
		{
			
			int middle = 0.5*(first + en);
			if ((bro->value - list_array[first]->value)*(bro->value - list_array[middle]->value) < 0)
			{
				en = middle;
			}
			else
			{
				first = middle;
			}
		}
		list.insert(list.begin() + 1, bro);
	}
}

void CAT_K_LIST::run_module(NODE* head)
{
	NODE* temp = (NODE*)new NODE(-1);
	while (num > 0)
	{
		temp->next = list_array[0];
		if (num == 1)
		{
			return;
		}
		list_array.erase(list_array.begin());
		temp = temp->next;
		//insert bro
		if (temp->next == NULL)
		{
			num = num - 1;
		}
		else
		{
			insert_brother(list_array, temp->next, num - 1);
		}
	}
}
#include "meet_arr.h"
#include <stdlib.h>


MEET_ARR::MEET_ARR() {}
MEET_ARR::~MEET_ARR() {}

int MEET_ARR::partition(int meets[][2], int start, int end)
{
	int privot[2] = { 0 };
	privot[0] = meets[start][0];
	privot[1] = meets[start][1];
	while (start < end)
	{
		while (start < end && privot[1] <= meets[end][1])
			end--;
		meets[start][0] = meets[end][0];
		meets[start][1] = meets[end][1];
		while (start<end && privot[1]>=meets[start][1])
			start++;
		meets[end][0] = meets[start][0];
		meets[end][1] = meets[start][1];
	}
	meets[start][0] = privot[0];
	meets[end][1] = privot[1];
	return start;
}

int MEET_ARR::partition(std::vector<std::vector<int>>& meets, int start, int end)
{
	int privot[2] = { 0 };
	privot[0] = meets[start][0];
	privot[1] = meets[start][1];
	while (start < end)
	{
		while (start < end && privot[1] <= meets[end][1])
			end--;
		meets[start][0] = meets[end][0];
		meets[start][1] = meets[end][1];
		while (start < end && privot[1] >= meets[start][1])
			start++;
		meets[end][0] = meets[start][0];
		meets[end][1] = meets[start][1];
	}
	meets[start][0] = privot[0];
	meets[end][1] = privot[1];
	return start;
}

void MEET_ARR::quick_sort(int meets[][2], int start, int end)
{
	if (start < end)
	{
		int gap = partition(meets, start, end);
		quick_sort(meets, start, gap - 1);
		quick_sort(meets, gap + 1, end);
	}
}

void MEET_ARR::quick_sort(std::vector<std::vector<int>>& meets, int start, int end)
{
	if (start < end)
	{
		int gap = partition(meets, start, end);
		quick_sort(meets, start, gap - 1);
		quick_sort(meets, gap + 1, end);
	}
}

int MEET_ARR::meet_calcu(int meets[][2], int nums)
{
	quick_sort(meets, 0, nums - 1);
	int count = 0;
	for (int i = 0; i < nums; i++)
	{
		int time = meets[i][1];
		int temp = 0;
		for (int j = i; j < nums; j++)
		{
			if (time >= meets[j][0])
				temp++;
		}
		if (temp > count)
			count = temp;
	}
	return count;
}

//void MEET_ARR::insert_node(NODE* head, int value, int count)
//{
//
//}
//
//NODE* MEET_ARR::malloc_list(int meets[][2], int nums)
//{
//	NODE* head = (NODE*)malloc(sizeof(NODE));
//	head->count = 0;
//	head->value = 0;
//	head->list = NULL;
//	for (int i = 0; i < nums; i++)
//	{
//
//	}
//}

int MEET_ARR::meet_ele(int meets[][2], int nums)
{
	std::vector<std::vector<int>> obj(nums * 2, std::vector<int>(2, 0));
	for (int i = 0; i < nums; i++)
	{
		obj[2 * i][0] = 1;
		obj[2 * i][1] = meets[i][0];
		obj[2 * i + 1][0] = -1;
		obj[2 * i + 1][1] = meets[i][1];
	}
	quick_sort(obj, 0, obj.size() - 1);
	int big = 0;
	int temp = 0;
	for (int i = 0; i < obj.size(); i++)
	{
		temp += obj[i][0];
		if (temp > big)
			big = temp;
	}
	return big;
}
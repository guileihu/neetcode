#include "overl_re.h"

OVERLAP::OVERLAP() {}
OVERLAP::~OVERLAP() {}

int OVERLAP::partition(int regions[][LEN], int start, int end)
{
	int privot[LEN] = { 0 };
	for (int i = 0; i < LEN; i++)
	{
		privot[i] = regions[start][i];
	}
	while (start < end)
	{
		while (start < end && regions[end][LEN - 1] >= privot[LEN - 1])
			end--;
		for (int i = 0; i < LEN; i++)
		{
			regions[start][i] = regions[end][i];
		}
		while (start < end && regions[start][LEN - 1] <= privot[LEN - 1])
		{
			start++;
		}
		for (int i = 0; i < LEN; i++)
		{
			regions[end][i] = regions[start][i];
		}
	}
	for (int i = 0; i < LEN; i++)
	{
		regions[start][i] = privot[i];
	}
	return start;
}

void OVERLAP::quick_sort(int regions[][LEN], int start, int end)
{
	if (start < end)
	{
		int gap = partition(regions, start, end);
		quick_sort(regions, start, gap - 1);
		quick_sort(regions, gap + 1, end);
	}
}

int OVERLAP::delete_region(int regions[][LEN], int nums)
{
	quick_sort(regions, 0, nums - 1);
	int temp[LEN] = { 0 };
	for (int i = 0; i < LEN; i++)
	{
		temp[i] = regions[0][i];
	}
	int i = 1;
	int delete_count = 0;
	while (i < nums)
	{
		if (temp[1] <= regions[i][0])
		{
			for (int j = 0; j < LEN; j++)
			{
				temp[j] = regions[i][j];
			}
		}
		else
		{
			delete_count++;
		}
		i++;
	}

	return delete_count;
}
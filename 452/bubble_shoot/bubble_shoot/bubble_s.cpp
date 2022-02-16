#include "bublle_s.h"
#include <stdlib.h>
#include <algorithm>

BUB::BUB() {
	start = INT_MAX;
}
BUB::~BUB() {}

void BUB::merge_regions(int bubs[][2], int rows)
{
	
}

int BUB::shoot_arrows(int bubs[][2], int rows)
{
	quicksort_bubs(bubs, 0, rows - 1);
	int arrow_count = 1;
	int sig = bubs[0][1];
	for (int i = 0; i < rows; i++)
	{
		if (bubs[i][0] > sig)
		{
			sig = bubs[i][1];
			arrow_count++;
		}
	}

	return arrow_count;
}

int BUB::patition(int bubs[][2], int start, int end)
{
	int privot[2];
	privot[0] = bubs[start][0];
	privot[1] = bubs[start][1];
	while (start < end)
	{
		while (start < end && bubs[end][1] >= privot[1])
			end--;
		bubs[start][0] = bubs[end][0];
		bubs[start][1] = bubs[end][1];
		while (start < end && bubs[start][1] <= privot[1])
			start++;
		bubs[end][0] = bubs[start][0];
		bubs[end][1] = bubs[start][1];
	}
	bubs[start][0] = privot[0];
	bubs[start][1] = privot[1];
	return start;
}

void BUB::quicksort_bubs(int bubs[][2], int start, int end)
{
	if (start < end)
	{
		int gap = patition(bubs, start, end);
		quicksort_bubs(bubs, start, gap - 1);
		quicksort_bubs(bubs, gap + 1, end);
	}
}

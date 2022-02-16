#ifndef _H_BUBBLE_H_
#define _H_BUBBLE_H_
#include <vector>
//#define LEN 2
typedef struct tab_list {
	int value;
	int len;
	std::vector<int> bubs_id;
	struct tab_list* tab;
}TAB_LIST;

class BUB {
public:
	BUB();
	~BUB();
	int shoot_arrows(int bubs[][2], int rows);
private:
	void quicksort_bubs(int bubs[][2], int start, int rows);
	int patition(int bubs[][2], int start, int rows);
	//int merge_region(int bubs[][2], int rows);
	void merge_regions(int bubs[][2], int rows);
	int start;
};

#endif

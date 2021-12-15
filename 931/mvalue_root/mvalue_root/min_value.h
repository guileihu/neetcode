#ifndef _H_MIN_VALUE_H_
#define _H_MIN_VALUE_H_
#include <vector>
#define COLS_NUM 3
//#define ROWS_NUM 3

class MIN_VALUE {
public:
	MIN_VALUE();
	~MIN_VALUE();
	int min_value_count(int nums[][COLS_NUM], int depth);
private:
	int min_array(std::vector<int> nums);
};



#endif

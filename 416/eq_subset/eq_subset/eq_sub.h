#ifndef EQ_SUB
#define EQ_SUB
#include <vector>

class SUBSET
{
public:
	SUBSET();
	~SUBSET();
	bool split(int arr[], int nums);
private:
	void insert(std::vector<int>& value,std::vector<int>& nums, int ae);
	bool make_up(std::vector<int> value, std::vector<int> nums, int sub_v);
};


#endif

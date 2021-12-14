// coincount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "max_len.h"

class VPDT_WARN
{
public:
	VPDT_WARN(int num);
	~VPDT_WARN();

	int get_num(int num);
	//void sense_reset(MFloat hmw_sensi, MFloat fcw_sensi, MFloat pcw_sensi, MFloat pvs_sensi);
	//void vpdt_warn(VPDT_INFO* vehicle_info, MInt32 vehicle_num, float ego_speed, MDouble time_stamp);
	//int sense_unint(MHandle hMemhgr);

private:
	int hmw_warn_info;
	int fcw_warn_info;
	int pvs_warn_info;
	int pcw_warn_info;
	int* dp;	
};

VPDT_WARN::VPDT_WARN(int num)
{
	dp = new int[num + 1];
}

VPDT_WARN::~VPDT_WARN(){
	delete(dp);
}

int VPDT_WARN::get_num(int leak)
{
	for (int i = 0; i <= leak; i++)
	{
		if (i == 0)
		{
			dp[i] = 0;
		}
		else if (i == 1 || i == 2 || i == 5)
		{
			dp[i] = 1;
		}
		else
		{
			if (i > 5)
			{
				dp[i] = std::min(dp[i - 5] + 1, dp[i - 2] + 1);
				dp[i] = std::min(dp[i], dp[i - 1] + 1);
			}
			else if (i > 2)
				dp[i] = std::min(dp[i - 2] + 1, dp[i - 1] + 1);
		}
	}
	return dp[leak];
}


//class Complex {
//public:
//	Complex();
//	~Complex();
//	int get_num(int leak);
//
//private:
//	int* dp;
//	int cost;
//};
////
//Complex::Complex() {
//	/*dp = new int[cos + 1];
//	for (int i = 0; i < cos + 1; i++)
//	{
//		dp[i] = -1;
//	}*/
//	//this->cost = cos;
//}
////
//Complex::~Complex()
//{
//	//delete(dp);
//}
////
//int Complex::get_num(int leak)
//{
//	for (int i = 0; i <= leak; i++)
//	{
//		if (i == 1 || i == 2 || i == 5)
//		{
//			dp[i] = 1;
//		}
//		else
//		{
//			if (i > 5)
//				dp[i] = std::min(dp[i - 5] + 1, dp[i - 2] + 1, dp[i - 1] + 1);
//			else if (i > 2)
//				dp[i] = std::min(dp[i - 2] + 1, dp[i - 1] + 1);
//		}
//	}
//	return dp[leak];
//}

int main()
{
	VPDT_WARN bit(15);
	int num=bit.get_num(11);
    std::cout <<num<< "Hello World!\n";
	MAX_LEN max_len(15);
	int array_num[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
	int len = sizeof(array_num) / sizeof(int);
	num = max_len.find_max_len(array_num, len);
	std::cout << num << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

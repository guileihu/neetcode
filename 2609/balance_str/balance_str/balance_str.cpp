// balance_str.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

int count_balance(const std::string str) {
    bool switch_0 = true;
    int length = 0;
    int len_0 = 0;
    int len_1 = 0;
    for (auto c : str) {
        if (switch_0) { //此时在统计0
            if (c == '0') {
                len_0++;
            } else if (len_0 > 0) {
                len_1++;
                switch_0 = false;
            } 
        } else { //此时在统计1
            if (c == '1') {
                len_1++;
            } else {
                switch_0 = true;
                // count
                int len = std::min(len_0, len_1);
                if (length < 2 * len) {
                    length = 2 * len;
                }
                len_0 = 1;
                len_1 = 0;
            }
        }
    }
    if (!switch_0) {
        int len = std::min(len_0, len_1);
        if (length < 2 * len) {
            length = 2 * len;
        }
    }
    return length;
}


int main()
{
    std::string str = "11100110";
    int len = count_balance(str);
    std::cout << len;
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

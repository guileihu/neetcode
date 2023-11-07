// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <string>
#include <iostream>
#include <algorithm>

bool is_vowel(const char c) {
    char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
    auto it = std::find(std::begin(vowel), std::end(vowel), c);
    if (it != std::end(vowel)) {
        return true;
    }
    else {
        return false;
    }
}

bool is_vowel_str(std::string str) {
    int len = str.length();
    if (is_vowel(str[0]) && is_vowel(str[len - 1])) {
        return true;
    }
    else {
        return false;
    } 
}

int count_vowel(const std::string strs[], int left, int right) {
    int count = 0;
    for (int i = left; i < right + 1; i++) {
        if (is_vowel_str(strs[i])) {
            count++;
        }
    }
    return count;
}







int main()
{
    std::string words[] = { "hey", "aeo", "mu", "ooo", "artro" };
    int count = count_vowel(words, 1, 4);
    std::cout << count;
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

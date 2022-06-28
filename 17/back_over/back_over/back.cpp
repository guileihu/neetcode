#include "back.h"
#include <iostream>

BACK_NUM::BACK_NUM(){
	line[0] = "abc";
	line[1] = "def";
	line[2] = "ghi";
	line[3] = "jkl";
	line[4] = "mno";
	line[5] = "pqrs";
	line[6] = "tuv";
	line[7] = "wxyz";
}

void BACK_NUM::search_print(std::string head, int len, int index, std::string digits)
{
	if (index == len)
	{
		std::cout << head << std::endl;
		return;
	}
	int line_num = digits[index] - '0' - 2;
	if (line_num < 0 || line_num>9)
	{
		std::cout << "illegal num!" << std::endl;
		return;
	}
	std::string line = this->line[line_num];
	for (int i = 0; i < line.length(); i++)
	{
		std::string temp_head = head + line[i];
		search_print(temp_head, len, index + 1, digits);
	}
	
}

void BACK_NUM::write_res(std::string digits)
{
	int len = digits.length();
	search_print("", len, 0, digits);
}
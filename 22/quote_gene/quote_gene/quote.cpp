#include "quote.h"
#include <iostream>
#include<stdio.h>
#include <string>

QUOTE::QUOTE(int n)
{
	this->n = n;
}

void QUOTE::generate_quote()
{
	int left_operate = n;
	int right_operate = n;
	quote_one_step(1, left_operate - 1, right_operate,"(");
	print_info();
}

void QUOTE::print_info()
{
	for (int i = 0; i < all_info.size(); i++)
	{
		std::string temp = all_info[i];
		std::cout << temp << std::endl;
	}
}

void QUOTE::quote_one_step(int value, int left_operate, int right_operate, std::string line)
{
	if (right_operate == 0)
	{
		all_info.push_back(line);
		return;
	}
	else if (left_operate == 0)
	{
		line = line + ")";
		value -= 1;
		quote_one_step(value, left_operate, right_operate - 1, line);
	}
	else 
	{
		if (value == 0)
		{
			line = line + "(";
			value += 1;
			quote_one_step(value, left_operate - 1, right_operate, line);
		}
		else
		{
			std::string temp_left = line+"(";
			int value_left = value + 1;
			quote_one_step(value_left, left_operate - 1, right_operate, temp_left);
			std::string temp_right = line + ")";
			int value_right = value - 1;
			quote_one_step(value_right, left_operate, right_operate - 1, temp_right);
		}
	}
}
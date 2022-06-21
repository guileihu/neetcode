#include "get_diff.h"
#include <iostream>

DIFF::DIFF(std::string line)
{
	this->line = line;
}

int DIFF::get_count()
{
	const char* ptr = line.c_str();
	int i = 0;
	std::string temp_line = "";
	int count = 0;
	while (ptr[i] != '\0')
	{
		if (not_exists(temp_line, ptr[i]))
		{
			temp_line.push_back(ptr[i]);
			count += 1;
		}
		i++;
	}
	std::cout << count << std::endl;
	return count;
}

bool DIFF::not_exists(std::string line, char c)
{
	const char* ptr = line.c_str();
	bool flag = true;
	int i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
			return false;
		i++;
	}
	return flag;
}
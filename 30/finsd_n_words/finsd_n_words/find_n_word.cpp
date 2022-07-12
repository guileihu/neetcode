#include "find_n_words.h"
#include <iostream>
N_WORDS::N_WORDS() {}

words_state::words_state(int size)
{
	for (int i = 0; i < size; i++)
	{
		this->state_count.push_back(0);
	}
}

bool words_state::push_value(int i, std::vector<int> count)
{
	index.push_back(i);
	if (state_count[i] < count[i])
	{		
		state_count[i] += 1;
	}
	else
	{
		while (index.size() > 0)
		{
			if (index[0] == i)
			{
				index.erase(index.begin());
				break;
			}
			else
			{
				index.erase(index.begin());
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] != state_count[i])
			return false;
	}
	return flag;

}

void N_WORDS::insert(std::string str)
{
	word_size = str.length();
	int i = 0;
	for (i = 0; i < words.size(); i++)
	{
		if (strcmp(str.c_str(), words[i].c_str()) == 0)
		{
			count[i] += 1;
			break;
		}
			
	}
	if (i == words.size())
	{
		words.push_back(str);
		count.push_back(1);
	}
}

int N_WORDS::match_word(std::string str)
{
	int index = -1;
	for (int i = 0; i < this->words.size(); i++)
	{
		if (strcmp(str.c_str(), words[i].c_str()) == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

void N_WORDS::get_pos(std::string src)
{
	int len = src.length();
	std::vector<words_state> dp(len, words_state(this->count.size()));
	int i = word_size - 1;
	while (i < len)
	{
		bool flag = false;
		if (i == 2)
		{
			int index = match_word(src.substr(0, 3));
			if (index != -1)
			{
				flag=dp[i].push_value(index, this->count);
			}
		}
		else
		{
			int index = match_word(src.substr(i-2, 3));
			if (index != -1)
			{
				dp[i] = dp[i - 3];
				flag=dp[i].push_value(index, this->count);
				std::cout << "get" << std::endl;
			}			
		}
		if (flag)
			printf("%d\t", i);
		i++;
	}
}

void N_WORDS::run_module(std::string src, std::string words[], int max_len)
{
	for (int i = 0; i < max_len; i++)
	{
		insert(words[i]);
	}
	get_pos(src);
	std::cout << "words" << std::endl;
}


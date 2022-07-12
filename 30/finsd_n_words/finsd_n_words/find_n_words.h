#ifndef _H_N_WORDS_H_
#define _H_N_WORDS_H_

#include <stdlib.h>
#include <string>
#include <vector>

class words_state
{
public:
	words_state(int size);
	bool push_value(int i, std::vector<int> count);
private:
	std::vector<int> state_count;
	std::vector<int> index;
};

class N_WORDS
{
public:
	N_WORDS();
	void run_module(std::string src, std::string words[], int max_len);
private:
	int word_size;
	std::vector<std::string> words;
	std::vector<int> count;
	void insert(std::string str);
	void get_pos(std::string src);
	int match_word(std::string str);
};


#endif // ! N_WORDS


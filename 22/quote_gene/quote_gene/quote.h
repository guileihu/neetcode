#ifndef _H_QUOTE_H_
#define _H_QUOTE_H_
#include <vector>

class QUOTE
{
public:
	QUOTE(int n);
	void generate_quote();

private:
	int n;
	std::vector<std::string> all_info;
	void quote_one_step(int value, int left_operate, int right_operate, std::string line);
	void print_info();
};

#endif

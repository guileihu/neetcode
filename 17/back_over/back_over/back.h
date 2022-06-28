#ifndef _H_BACK_H_
#define _H_BACK_H_
#include <string>


class BACK_NUM
{
public:
	BACK_NUM();
	void write_res(std::string digits);
private:
	std::string line[8];
	void search_print(std::string head, int len, int index, std::string digits);
};

#endif

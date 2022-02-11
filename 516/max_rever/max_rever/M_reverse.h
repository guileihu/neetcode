#ifndef _H_MAX_REVE_H_
#define _H_MAX_REVE_H_

#include <string>

class MAX_REVE {
public:
	MAX_REVE();
	~MAX_REVE();
	int count_max(std::string str);

private:
	int same_sub_str(std::string str1, std::string str2);

};

#endif

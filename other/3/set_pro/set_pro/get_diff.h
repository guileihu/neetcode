#ifndef GET_DIFF
#define GET_DIFF

#include <string>

class DIFF
{
public:
	DIFF(std::string line);
	int get_count();
private:
	std::string line;
	bool not_exists(std::string line, char c);
};

#endif

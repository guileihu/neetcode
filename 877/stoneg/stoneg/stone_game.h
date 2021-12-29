#ifndef _H_S_GAME_H_
#define _H_S_GAME_H_

class Pair {
public:
	int fir;
	int sec;
	Pair(int fir, int sec) {
		this->fir = fir;
		this->sec = sec;
	}
};

class S_GAME {
public:
	S_GAME();
	~S_GAME();
	int judge_score(int piles[], int n);
};

#endif

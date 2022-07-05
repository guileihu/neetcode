#ifndef _H_REVER_LOCAL_H_
#define _H_REVER_LOCAL_H_

typedef struct node{
	int value;
	struct node* next;
}P_NODE;

class REVER_LOCAL
{
public:
	void run_module(P_NODE* head);
private:
	P_NODE* p1;
	P_NODE* p2;
};


#endif

#ifndef _H_TREE_ROB_H_
#define _H_TREE_ROB_H_

#include <vector>

typedef struct tnode{
	int value;
	struct tnode* left_child;
	struct tnode* right_child;
}TREE_NODE;

class TREE_ROB
{
public:
	TREE_ROB();
	~TREE_ROB();
	float tree_max_rob(int arr[], int max_num);
private:
	void build_tree(std::vector<int>& arr, std::vector<TREE_NODE*> vec);
	void set_node(TREE_NODE** node, int value);
	float rob_tree(TREE_NODE* root);
	float rob_node(TREE_NODE* node);
	float nrob_node(TREE_NODE* node);
};

#endif

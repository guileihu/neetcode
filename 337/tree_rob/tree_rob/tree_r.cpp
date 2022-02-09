#include "tree_r.h"
#include <algorithm>

TREE_ROB::TREE_ROB() {}
TREE_ROB::~TREE_ROB() {};

void TREE_ROB::set_node(TREE_NODE** node, int value)
{
	if (value == -1)
	{
		*node = NULL;
	}
	else
	{
		TREE_NODE* temp = (TREE_NODE*)malloc(sizeof(TREE_NODE));
		temp->value = value;
		temp->left_child = NULL;
		temp->right_child = NULL;
		*node = temp;
	}
}

void TREE_ROB::build_tree(std::vector<int>& arr, std::vector<TREE_NODE*> vec)
{
	if (arr.size() == 0)
		return;

	std::vector<TREE_NODE*> vecc;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == NULL)
		{
			arr.erase(arr.begin());
			arr.erase(arr.begin());
			vecc.push_back(NULL);
			vecc.push_back(NULL);
		}
		else
		{
			TREE_NODE* left_child;
			set_node(&left_child, arr[0]);
			arr.erase(arr.begin());
			vec[i]->left_child = left_child;

			TREE_NODE* right_child;
			set_node(&right_child, arr[0]);
			arr.erase(arr.begin());
			vec[i]->right_child = right_child;

			vecc.push_back(vec[i]->left_child);
			vecc.push_back(vec[i]->right_child);
		}
	}
	std::vector<TREE_NODE*>().swap(vec);
	build_tree(arr, vecc);
}

float TREE_ROB::nrob_node(TREE_NODE* node)
{
	if (node == NULL)
		return 0;
	return rob_tree(node->left_child) + rob_tree(node->right_child);
}

float TREE_ROB::rob_node(TREE_NODE* node)
{
	float left_value = nrob_node(node->left_child);
	float right_value = nrob_node(node->right_child);
	return node->value + left_value + right_value;
}

float TREE_ROB::rob_tree(TREE_NODE* node)
{
	if (node == NULL)
		return 0;
	//rob
	int res = std::max(rob_node(node), nrob_node(node));
	return res;
}

float TREE_ROB::tree_max_rob(int arr[], int max_num)
{
	std::vector<int> house;
	for (int i = 0; i < max_num; i++)
	{
		house.push_back(arr[i]);
	}
	std::vector<TREE_NODE*> vec;
	TREE_NODE* root;
	set_node(&root, house[0]);
	house.erase(house.begin());
	vec.push_back(root);
	build_tree(house,vec);
	float res = rob_tree(root);
	return res;
}
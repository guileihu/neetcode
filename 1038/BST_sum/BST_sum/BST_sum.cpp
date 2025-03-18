// BST_sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>

struct TREENODE {
    int val;
    int sum_val;
    TREENODE* leftchild;
    TREENODE* rightchild;
    TREENODE(): val(0), leftchild(nullptr), rightchild(nullptr), sum_val(0) {};
    TREENODE(int val_, int sum_val_) : val(val_), leftchild(nullptr), rightchild(nullptr), sum_val(sum_val_) {};
};

void fillnode(std::vector<TREENODE*> node_vec, int array[], int size, int i) {
    if (i >= size) {
        return;
    }
    std::vector<TREENODE*> node_next;
    for (auto& o : node_vec) {
        TREENODE* leftchild = new TREENODE(array[i], 0);
        i = i + 1;
        TREENODE* right_child = new TREENODE(array[i], 0);
        i = i + 1;
        node_next.push_back(leftchild);
        node_next.push_back(right_child);
        o->leftchild = leftchild;
        o->rightchild = right_child;
    }
}

void reset_tree(int array[], int size) {

}

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

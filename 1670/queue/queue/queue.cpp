// queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


struct ListNode {
    int value = 0;
    ListNode* next = NULL;
    ListNode* pre = NULL;
};

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        head = (ListNode*) malloc(sizeof(ListNode));
        tail = (ListNode*)malloc(sizeof(ListNode));
        middle = (ListNode*)malloc(sizeof(ListNode));
        head->next = tail;
        tail->pre = head;
    }

    void pushFront(int val) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->value = val;
        node->pre = head;
        node->next = head->next;
        head->next = node;
        left_num++;
        num++;
        if (num == 1) {
            middle = node;
            left_num = 0;
            right_num = 0;
        }
        else {
            if (left_num > right_num) {
                middle = middle->pre;
                left_num--;
                right_num++;
            }
        }
    }

    void pushMiddle(int val) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->value = val;
        if (num == 0) {
            node->pre = head;
            node->next = head->next;
            head->next = node;
            middle = node;
        }
        else {
            if (left_num < right_num) {
                node->pre = middle->pre;
                node->next = middle;
                middle->pre->next = node;
                middle->pre = node;   
                left_num++;
            }
            else {
                node->pre = middle;
                node->next = middle->next;
                middle->next->pre = node;
                middle->next = node;
                right_num++;
            }    
        }
        num++;
    }

    void pushBack(int val) {
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->value = val;
        node->next = tail;
        node->pre = tail->pre;
        tail->pre = node;
        right_num++;
        if (num == 1) {
            middle = node;
            left_num = 0;
            right_num = 0;
        }
        else {
            if (right_num - 1 > left_num) {
                middle = middle->next;
                right_num--;
                left_num++;
            }
        }
        num++;
    }

    int popFront() {
        ListNode* node = head->next;
        int val = node->value;
        head->next = node->next;
        node->next->pre = head;
        left_num--;
        num--;
        if (num == 0) {
            middle = tail;
            left_num = 0;
            right_num = 0;
        }
        else {
            if (right_num - 1 > left_num) {
                middle = middle->next;
                right_num--;
                left_num++;
            }
        }
        free(node);
        return val;
    }

    int popMiddle() {
        ListNode* node = middle;
        int val = node->value;
        num--;
        if (num == 0) {
            middle = tail;
            left_num = 0;
            right_num = 0;
        }
        else {
            if (left_num == right_num) {
                middle = middle->pre;
                left_num--;
            }
            else {
                middle = middle->next;
                right_num++;
            }
        }
        free(node);
        return val;
    }

    int popBack() {
        ListNode* node = tail->pre;
        int val = node->value;
        num--;
        right_num--;
        if (num == 0) {
            middle = tail;
            left_num = 0;
            right_num = 0;
        }
        else {
            if (right_num < left_num) {
                middle = middle->pre;
                right_num++;
                left_num--;
            }
        }
        free(node);
        return val;
    }
private:
    int left_num = 0;
    int right_num = 0;
    int num = 0;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* middle = NULL;
};


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

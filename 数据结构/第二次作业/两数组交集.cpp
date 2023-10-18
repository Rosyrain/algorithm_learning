//
// Created by Rosyrain on 2023/10/18.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersection(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode(0);  // 创建一个虚拟头节点
    ListNode* tail = dummy;  // 用于记录交集链表的尾节点

    ListNode* p1 = a;
    ListNode* p2 = b;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p1 = p1->next;
        } else if (p1->val > p2->val) {
            p2 = p2->next;
        } else {
            tail->next = new ListNode(p1->val);  // 将交集节点添加到交集链表中
            tail = tail->next;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return dummy->next;  // 返回交集链表的头节点
}

int main() {
    // 创建链表a: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);

    // 创建链表b: 2 -> 4 -> 6
    ListNode* b = new ListNode(2);
    b->next = new ListNode(4);
    b->next->next = new ListNode(6);

    // 求交集并存入a链表中
    ListNode* result = getIntersection(a, b);

    // 打印交集链表的值
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}

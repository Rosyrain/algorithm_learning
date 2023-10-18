#include <iostream>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findMaxNode(ListNode* head) {
    ListNode* maxNode = head;
    int maxValue = INT_MIN;

    ListNode* curr = head;
    while (curr != NULL) {
        if (curr->val > maxValue) {
            maxValue = curr->val;
            maxNode = curr;
        }
        curr = curr->next;
    }

    return maxNode;
}

int main() {
    // 创建链表: 1 -> 5 -> 3 -> 2 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);

    // 找到链表中值最大的节点
    ListNode* maxNode = findMaxNode(head);

    // 输出最大值节点的值
    cout << "最大值节点的值为: " << maxNode->val << endl;

    return 0;
}

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include "../common/ListNode.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode head = {0, NULL};
    struct ListNode* tail = &head;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            tail->next = p1;
            p1 = p1->next;
        }
        else {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    tail->next = p1 ? p1 : p2;
    return head.next;
}

int main() {
    struct ListNode a3 = {4, NULL};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};

    struct ListNode b3 = {4, NULL};
    struct ListNode b2 = {3, &b3};
    struct ListNode b1 = {1, &b2};

    struct ListNode* head = mergeTwoLists(&a1, &b1);
    printList(head);
    return 0;
}

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

#include "../common/ListNode.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL) return NULL;
    // [0, k-1] => [head, tail]
    struct ListNode* cur = head;
    for (int i = 0; i < k-1; ++i) {
        cur = cur->next;
        if (cur == NULL) return head;
    }
    struct ListNode* tail = cur;
    struct ListNode* nodek = cur->next;
    tail->next = NULL;
    struct ListNode* head1 = reverseList(head);
    struct ListNode* tail1 = head;
    struct ListNode* head2 = reverseKGroup(nodek, k);
    tail1->next = head2;
    return head1;
}

int main() {
    struct ListNode a5 = {5, NULL};
    struct ListNode a4 = {4, &a5};
    struct ListNode a3 = {3, &a4};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};
    struct ListNode* head = reverseKGroup(&a1, 2);
    printList(head);
    return 0;
}

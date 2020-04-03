/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#include "../common/ListNode.h"

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode* node1 = head;
    struct ListNode* node2 = head->next;
    node1->next = swapPairs(node2->next);
    node2->next = node1;
    return node2;
}

int main() {
    struct ListNode a3 = {3, NULL};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};
    struct ListNode* head = swapPairs(&a1);
    printList(head);
    return 0;
}

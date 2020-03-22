/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *p1, *p2;
    p1 = p2 = &dummy;
    while (n-- >= 0) {
        p1 =  p1->next;
    }
    while (p1) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p2->next = p2->next->next;
    return dummy.next;
}

#include <stdio.h>
void printListNode(struct ListNode* head) {
    if (!head) return;
    struct ListNode* node = head;
    printf("%d", head->val);
    while ((node = node->next) != NULL) {
        printf(" -> %d", node->val);
    }
    printf("\n");
}

int main() {
    struct ListNode n5 = {5, NULL};
    struct ListNode n4 = {4, &n5};
    struct ListNode n3 = {3, &n4};
    struct ListNode n2 = {2, &n3};
    struct ListNode n1 = {1, &n2};
    printListNode(&n1);
    struct ListNode* head = removeNthFromEnd(&n1, 2);
    printListNode(head);
    return 0;
};

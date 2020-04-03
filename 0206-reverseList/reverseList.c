#include "../common/ListNode.h"

/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

struct ListNode* reverseListRecursion(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    struct ListNode* newHead = reverseListRecursion(head->next);
    struct ListNode* newTail = head->next;
    newTail->next = head;
    head->next = NULL;
    return newHead;
}

/*
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next;
    while (cur) {
        next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }
    return prev;
}
*/

int main() {
    struct ListNode a5 = {5, NULL};
    struct ListNode a4 = {4, &a5};
    struct ListNode a3 = {3, &a4};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};
    struct ListNode* head = reverseListRecursion(&a1);
    printList(head);
    return 0;
}

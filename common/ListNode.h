#include <stdio.h>
#include <stdlib.h>

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

void printList(struct ListNode* head) {
    if (!head) return;
    struct ListNode* next = head;
    printf("%d", head->val);
    while ((next = next->next) != NULL) {
        printf(" -> %d", next->val);
    }
    printf("\n");
}

void freeList(struct ListNode* head) {
    if (!head) return;
    struct ListNode* next = head;
    struct ListNode* cur;
    while (next) {
        cur = next;
        next = next->next;
        free(cur);
    }
}

struct ListNode* reverseList(struct ListNode* head) {
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

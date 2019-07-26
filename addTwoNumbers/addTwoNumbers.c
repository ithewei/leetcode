/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode* next;
};

// result should be freed by call freeListNode
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* head = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* back = NULL;
    int carry = 0;
    while (p1 || p2 || carry) {
        back = (struct ListNode*)malloc(sizeof(struct ListNode));
        back->val = carry;
        back->next = NULL;
        if (p1) {
            back->val += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            back->val += p2->val;
            p2 = p2->next;
        }
        carry = back->val / 10;
        back->val %= 10;
        if (!head)      head = back;
        if (prev)       prev->next = back;
        prev = back;
    }
    return head;
}

void freeListNode(struct ListNode* l) {
    struct ListNode* prev = NULL;
    struct ListNode* next = l;
    while (next) {
        prev = next;
        next = next->next;
        free(prev);
    }
}

void printListNode(struct ListNode* l) {
    struct ListNode* next = l;
    while (next) {
        if (next == l) {
            printf("%d", next->val);
        }
        else {
            printf(" -> %d", next->val);
        }
        next = next->next;
    }
    printf("\n");
}

int main() {
    struct ListNode la_1;
    struct ListNode la_2;
    struct ListNode la_3;
    la_1.next = &la_2;
    la_2.next = &la_3;
    la_3.next = NULL;
    la_1.val = 2;
    la_2.val = 4;
    la_3.val = 3;
    struct ListNode lb_1;
    struct ListNode lb_2;
    struct ListNode lb_3;
    lb_1.next = &lb_2;
    lb_2.next = &lb_3;
    lb_3.next = NULL;
    lb_1.val = 5;
    lb_2.val = 6;
    lb_3.val = 4;

    struct ListNode* result = addTwoNumbers(&la_1, &lb_1);
    printListNode(result);
    freeListNode(result);
    return 0;
}

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

#include "../common/ListNode.h"

// result should be freed by call freeListNode
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;
    int carry = 0;
    int sum;
    while (p1 || p2 || carry) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        sum = carry;
        if (p1) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            sum += p2->val;
            p2 = p2->next;
        }
        carry = sum / 10;
        node->val = sum % 10;
        node->next = NULL;
        tail->next = node;
        tail = node;
    }
    return dummy.next;
}

int main() {
    struct ListNode la_3 = {3, NULL};
    struct ListNode la_2 = {4, &la_3};
    struct ListNode la_1 = {2, &la_2};
    struct ListNode lb_3 = {4, NULL};
    struct ListNode lb_2 = {6, &lb_3};
    struct ListNode lb_1 = {5, &lb_2};

    struct ListNode* result = addTwoNumbers(&la_1, &lb_1);
    printList(result);
    freeList(result);
    return 0;
}

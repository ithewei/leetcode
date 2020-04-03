/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

#include <stdio.h>
#include <vector>
using namespace std;

#include "../common/ListNode.h"

class Solution {
public:
    ListNode* merge2Lists(ListNode* L1, ListNode* L2) {
        ListNode* p1 = L1;
        ListNode* p2 = L2;
        struct ListNode head = {0, NULL};
        ListNode* tail = &head;
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

    ListNode* mergeLists(vector<ListNode*>& lists, int begin, int end) {
        if (begin == end) return lists[begin];
        int mid = (begin + end) / 2;
        ListNode* L1 = mergeLists(lists, begin, mid);
        ListNode* L2 = mergeLists(lists, mid + 1, end);
        return merge2Lists(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        return mergeLists(lists, 0, lists.size() - 1);
    }
};

int main() {
    Solution sln;
    vector<ListNode*> lists;
    struct ListNode a3 = {4, NULL};
    struct ListNode a2 = {2, &a3};
    struct ListNode a1 = {1, &a2};

    struct ListNode b3 = {4, NULL};
    struct ListNode b2 = {3, &b3};
    struct ListNode b1 = {1, &b2};

    struct ListNode c3 = {5, NULL};
    struct ListNode c2 = {3, &c3};
    struct ListNode c1 = {1, &c2};
    lists.push_back(&a1);
    lists.push_back(&b1);
    lists.push_back(&c1);

    ListNode* head = sln.mergeKLists(lists);
    printList(head);
    return 0;
}

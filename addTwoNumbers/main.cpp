#include<stdio.h>
#include<malloc.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	struct ListNode *lhead = NULL;
	struct ListNode *ltmp = NULL;
	int add = 0;
	while (l1 != NULL || l2 != NULL || add != 0){
		if (l1 != NULL){
			add += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL){
			add += l2->val;
			l2 = l2->next;
		}
		struct ListNode *lcur = (struct ListNode*)malloc(sizeof(struct ListNode));
		lcur->next = NULL;
		lcur->val = add % 10;
		add = add / 10;
		if (lhead == NULL){
			lhead = lcur;
		}
		if (ltmp != NULL){
			ltmp->next = lcur;
		}
		ltmp = lcur;
	}
	return lhead;
}

int main(){
	struct ListNode *l1 = NULL;
	for (int i = 1; i < 5; i++){
		struct ListNode *ltmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		ltmp->val = i;
		ltmp->next = l1;
		l1 = ltmp;
	}
	struct ListNode *l2 = NULL;
	for (int i = 7; i < 10; i++){
		struct ListNode *ltmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		ltmp->val = i;
		ltmp->next = l2;
		l2 = ltmp;
	}
	struct ListNode *lret = addTwoNumbers(l1,l2);
	while (lret != NULL){
		printf("%d->", lret->val);
		lret = lret->next;
	}

	return 0;
}

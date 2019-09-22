/*************************************************************************
	> File Name: 2_addTwoNumbers.c
	> Author: DennisGao
	> Mail: DennisGao 
	> Created Time: 2019年09月22日 星期日 21时15分33秒
 ************************************************************************/

/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include<stdio.h>
#include<stdlib.h>


/**
 * Definition for singly-linked list.
 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
}List;

typedef struct ListNode* PtrNode;

struct ListNode* copyList(struct ListNode* src, struct ListNode* dst)
{
	struct ListNode* newNode = NULL;
	struct ListNode* tmp = src;
	struct ListNode* newTmp = NULL;
	dst = newTmp;

	do {
		newNode = malloc(sizeof(struct ListNode));

		newNode->val = tmp->val;
		newTmp->next = newNode;
	
	} while (tmp->next != NULL)
	return dst;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* sumList = NULL;
	
	struct ListNode* tmpNode = malloc(sizeof(struct ListNode));
	tmpNode->val = 0;
	tmpNode->next = NULL;

	sumList = tmpNode;

	// if(list1.head == 0 or list2.head == 0 and next == NULL), copy another list to sumList
	if (l1->val == 0 && l1->next == NULL)
		return copyList(l2, sumList);
	
	if (l2->val == 0 && l2->next == NULL)
		return copyList(l1, sumList);

	// iterate list1 and 2, sum (list1+list2+upgrade) and add to sumList, save sum%10, if > 10, bool upgrade=1, else upgrade=0;

	return sumList;
}

int main(int argc, char* argv[])
{
	return 0;
}


#include<iostream>
#include<string>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int len1 = link_size(l1);
		int len2 = link_size(l2);

		if (len1 == 0 || len2 == 0)
			return len1 == 0 ? l2 : l1;
		if (len2 > len1)
		{
			ListNode *t = l1;
			l1 = l2;
			l2 = t;
		}
		//cout << len1 << endl;

		//ListNode *ret = (ListNode*)malloc(sizeof(ListNode));
		ListNode *ret = new ListNode(-1);
		ListNode *temp, *r;
		r = ret;
		//ListNode *ret = l1;
		int a = 0, b = 0, c = 0, flag = 0;
		//ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
		while (l1)
		{
			a = l1->val;
			if (l2)
				b = l2->val;
			else
				b = 0;
			if (flag)
				c = a + b + 1;
			else
				c = a + b;
			if (c > 9)
				flag = 1;
			else
				flag = 0;

			c = c % 10;
			temp = new ListNode(c);
			//temp->val = c;
			r->next = temp;
			r = temp;
			/*l1->val = c;*/

			l1 = l1->next;
			if (l2)
				l2 = l2->next;
			/*if (l1->next == NULL)
			temp = l1;*/
		}

		if (flag)
		{
			ListNode *p = new ListNode(1);
			//p->val = 1;
			p->next = NULL;
			r->next = p;
			r = p;
		}

		//cout << link_size(l1) << endl;
		r->next = NULL;
		return ret->next;
		//return ret;
	}

	int link_size(ListNode *l)
	{
		int size = 0;
		while (l)
		{
			size++;
			l = l->next;
		}
		return size;
	}
};

int main()
{
	Solution so;
	ListNode *node1 = (ListNode*)malloc(sizeof(ListNode));
	node1->val = 4;
	ListNode *node2 = (ListNode*)malloc(sizeof(ListNode));
	node2->val = 6;
	ListNode *node3 = (ListNode*)malloc(sizeof(ListNode));
	node3->val = 2;
	ListNode *node4 = (ListNode*)malloc(sizeof(ListNode));
	node4->val = 6;
	ListNode *node5 = (ListNode*)malloc(sizeof(ListNode));
	node5->val = 4;
	ListNode *node6 = (ListNode*)malloc(sizeof(ListNode));
	node6->val = 7;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;
	ListNode *l;
	l=so.addTwoNumbers(node1, node4);
	while (l)
	{
		cout << l->val << endl;
		l = l->next;
	}
	return 0;
}
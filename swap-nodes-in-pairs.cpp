#include<iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *p, *q, *r,*res;
		if (head == NULL)
			return head;
		else if (head->next == NULL)
			return head;
		p = head;
		q = head->next;
		res = head->next;
		while (p)
		{
			r = q->next;
			q->next = p;
			p->next = r;
			p = r; 
			if (p)
				q = p->next;
		}
		return res;
	}
};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	Solution so;
	cout << (so.swapPairs(node1))->val << endl;
	return 0;
}
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution_demo {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* prev = prehead;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 != NULL ? l1 : l2;

        return prehead->next;
    }
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2, *p3, *head;
		if (p1 == NULL) return p2;
		if (p2 == NULL) return p1;
		if (p1->val <= p2->val) { head = p1; p1 = p1->next; }
		else { head = p2; p2 = p2->next; }
		p3 = head;
		while (p1 != NULL || p2 != NULL) {
			if (p1 == NULL) {
				p3->next = p2;
				break;
			}
			if (p2 == NULL) {
				p3->next = p1;
				break;
			}
			if (p1->val <= p2->val) {
				p3->next = p1;
				p3 = p3->next;
				p1 = p1->next;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
				p2 = p2->next;
			}
		}
		return head;
	}
};


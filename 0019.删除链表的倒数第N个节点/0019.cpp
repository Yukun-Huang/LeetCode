/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> ptrVec;
		int size = 0;
		ListNode* ptr = head;
		while (ptr != NULL) {
			ptrVec.push_back(ptr);
			size++;
			ptr = ptr->next;
		}
		int target_idx = size - n;
		ListNode* ptr_out = ptrVec[target_idx]->next;
		if (target_idx) {
			ptrVec[target_idx - 1]->next = ptr_out;
		}
		else {
			head = ptr_out;
		}
		return head;
	}
};
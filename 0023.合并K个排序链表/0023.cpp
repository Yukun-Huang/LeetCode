/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// 1.����k��listָ��ָ��NULLʱ�������޳���vector. ��vector.size()==1ʱ������whileѭ������ʣ�µ�ָ�봫�ݸ����ս�
// 2.����һ������findMinIndex���ҳ���Сֵ���ڵ�list������
// ע�⣬�ýⷨʱ�临�Ӷ�ΪO(kN)��ʵ����ʹ�����ȶ��л��߷��η������Ż���O(Nlogk).

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		// remove NULL ptr
		for (int cnt = lists.size() - 1; cnt >= 0; cnt--) {
			if (lists[cnt] == NULL)
				lists.erase(lists.begin() + cnt);
		}
		// empty vector
		if (!lists.size())
			return NULL;

		ListNode* prehead = new ListNode(-1);
		ListNode* prev = prehead;
		int minIdx = -1;

		while (lists.size() > 1) {
			minIdx = findMinIndex(lists);
			prev->next = lists[minIdx];
			prev = prev->next;
			lists[minIdx] = lists[minIdx]->next;
			if (lists[minIdx] == NULL)
				lists.erase(lists.begin() + minIdx);
		}
		prev->next = lists[0];
		return prehead->next;
	}

	int findMinIndex(vector<ListNode*>& lists) {
		int minIdx = -1;
		int minVal = INT_MAX;
		int count = 0;
		for (ListNode* li : lists) {
			if (li->val <= minVal) {
				minVal = li->val;
				minIdx = count;
			}
			count++;
		}
		return minIdx;
	}
};


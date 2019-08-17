/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// 1.当第k个list指针指向NULL时，将其剔除出vector. 当vector.size()==1时，跳出while循环，将剩下的指针传递给最终解
// 2.定义一个函数findMinIndex，找出最小值所在的list的索引
// 注意，该解法时间复杂度为O(kN)，实际上使用优先队列或者分治法可以优化到O(Nlogk).

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


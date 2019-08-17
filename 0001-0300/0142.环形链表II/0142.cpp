/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  // _Floyd
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pt_fast = head, *pt_slow = head;
        // phase 1
        while(pt_fast != NULL && pt_fast->next != NULL){
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next->next;
            if (pt_slow == pt_fast)
                break;
        }
        if (pt_fast == NULL || pt_fast->next == NULL)
            return NULL;
        // phase 2
        pt_slow = head;
        while (pt_slow != pt_fast){
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next;
        }
        return pt_slow;
    }
};

class Solution_hash {
public:
    ListNode *detectCycle(ListNode *head) {
        int cnt = 0;
        unordered_map<ListNode*, int> hm;
        ListNode *pt = head;
        while(pt != NULL && (!hm.count(pt))){
            hm.insert(pair<ListNode*, int>(pt, cnt));
            pt = pt->next;
            cnt++;
        }
        return pt;
    }
};


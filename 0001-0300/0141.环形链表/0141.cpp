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
    bool hasCycle(ListNode *head) {
        ListNode *pFast = head;
        ListNode *pSlow = head;
        while(pFast != NULL && pFast->next != NULL){
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast)
                return true;
        }
        return false;
    }
};
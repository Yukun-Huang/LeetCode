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
    // 反转链表
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *start = NULL, *pt = NULL;
        while (head){
            pt = head;
            head = head->next;
            pt->next = start;
            start = pt;
        }
        return start;
    }
    
    // 快慢指针找中点
    ListNode* findMiddle(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *pt_fast = head, *pt_slow = head;
        while (pt_fast && pt_fast->next){
            pt_slow = pt_slow->next;
            pt_fast = pt_fast->next->next;
        }
	    return pt_slow;
    }
    
    bool isPalindrome(ListNode* head) {
        if ((!head) || !(head->next)) return true;
        // find middle position
        ListNode *mid, *start = head;
        mid = findMiddle(head);
        mid = reverse(mid);
        // judge palindrome
        while (mid){
            if (mid->val != start->val)
                return false;
            mid = mid->next;
            start = start->next;
        }
        return true;
    }
};

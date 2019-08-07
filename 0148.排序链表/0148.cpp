/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 链表归并排序的递归实现
  1.返回边界情况
  2.用快慢指针法分割链表
  3.排序左右链表(递归)
  4.合并左右链表(新建一个头指针,依次往后添加元素)
  5.返回结果
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // phase 1
        if (head == NULL || head->next == NULL)
            return head;
        // phase 2
        ListNode *slow = head, *fast = head, *mid;
        fast = fast->next;  // 注意！这里让fast比slow先走一步，从而避免了节点为2时无限递归的错误！
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        mid = slow->next;
        slow->next = NULL;
        // phase 3
        ListNode *left, *right;
        left = sortList(head);
        right = sortList(mid);
        // phase 4
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        while (left != NULL && right != NULL){
            if (left->val < right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        if (left == NULL) dummy->next = right;
        else dummy->next = left;
        // phase 5
        return res->next;
    }
};

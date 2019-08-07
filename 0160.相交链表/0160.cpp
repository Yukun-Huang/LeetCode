/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表首尾相连
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptA = headA, *ptB = headB;
        while (ptA != ptB){
            ptA = ptA ? ptA->next : headB;
            ptB = ptB ? ptB->next : headA;
        }
        return ptA;
    }
};


/*
相交链表
1.找到链表A、B的末尾节点，记录两个链表的长度，时间O(n)
2.如果结尾节点不相同，说明不相交，返回NULL
3.计算链表的长度差值D，让较长的那个链表先走D步
4.两指针遍历直到指向相同，相同节点即为所求
*/
class Solution_my {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // phase 1
        int cntA = 0, cntB = 0;
        ListNode *ptA = headA, *ptB = headB, *endA = headA, *endB = headB;
        while (ptA != NULL || ptB != NULL){
            if (ptA != NULL){
                cntA++;
                if (ptA->next == NULL) endA = ptA;
                ptA = ptA->next;
            }
            if (ptB != NULL){
                cntB++;
                if (ptB->next == NULL) endB = ptB;
                ptB = ptB->next;
            }
        }
        if (endA != endB)
            return NULL;
        // phase 2
        int delta = abs(cntA - cntB);
        if (cntA < cntB)
            ptA = headB, ptB = headA;
        else
            ptA = headA, ptB = headB;
        while (delta){
            ptA = ptA->next;
            delta--;
        }
        while (ptA != ptB){
            ptA = ptA->next;
            ptB = ptB->next;
        }
        return ptA;
    }
};



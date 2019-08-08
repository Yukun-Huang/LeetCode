// 注意事项！！！
// 把头结点移到尾部时一定要记得让head->next置空啊！不然就成环了啊！！

// 迭代解法
// 遍历所有节点，依次接到头结点的尾部
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

// 递归解法
// 当前链表的反转 = 将头结点接到后续链表的反转的尾部
class Solution_recursive {
public:
    ListNode* tail = NULL;
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* newhead = reverseList(head->next);
        if (!tail)
            tail = newhead;
        head->next = NULL;
        tail->next = head;
        tail = head;
        return newhead;
    }
};
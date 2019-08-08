// ע���������
// ��ͷ����Ƶ�β��ʱһ��Ҫ�ǵ���head->next�ÿհ�����Ȼ�ͳɻ��˰�����

// �����ⷨ
// �������нڵ㣬���νӵ�ͷ����β��
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

// �ݹ�ⷨ
// ��ǰ����ķ�ת = ��ͷ���ӵ���������ķ�ת��β��
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
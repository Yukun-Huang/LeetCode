/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

typedef long long ll;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *p1 = l1, *p2 = l2;
        ll v = 0, inc = 0;
        while (1){
            // calc
            v = p1->val + p2->val + inc;
            inc = v / 10;
            v = v % 10;
            p1->val = v;
            // exit
            if (p1->next == NULL && p2->next == NULL){
                if (inc){
                    p1->next = new ListNode(inc);
                }
                break;
            }
            else if (p1->next == NULL){
                p1->next = new ListNode(0);
            }
            else if (p2->next == NULL){
                p2->next = new ListNode(0);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return l1;
    }
};


int main(){
    // case 1
//    ListNode *l1 = new ListNode(0);
//    ListNode *p1 = l1;
//    p1->next = new ListNode(2); p1 = p1->next;
//    p1->next = new ListNode(9);
//
//    ListNode *l2 = new ListNode(1);
//    ListNode *p2 = l2;
//    p2->next = new ListNode(2); p2 = p2->next;
//    p2->next = new ListNode(9);

    // case 2
    // case 1
    ListNode *l1 = new ListNode(0);
    ListNode *p1 = l1;
    p1->next = new ListNode(2); p1 = p1->next;
    p1->next = new ListNode(9);

    ListNode *l2 = new ListNode(1);
    ListNode *p2 = l2;
    p2->next = new ListNode(8);

    Solution S = Solution();
    ListNode *ans = S.addTwoNumbers(l1, l2);

    ListNode *pa = ans;
    do{
        cout << pa->val << ' ';
        pa = pa->next;
    }
    while(pa != NULL);
}
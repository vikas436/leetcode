// 24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* pre=NULL,*next=second;
        while(first!=NULL) {
            second=first->next;
            if(second != NULL) {
                first->next=second->next;
                second->next =first;
            } else {
                pre->next=first;
                break;
            }
             if(pre==NULL) {
                 pre = first;
             } else {
                 pre->next = second;
                 pre=first;
             }
             first=first->next;
        }
        return next;
    }
};

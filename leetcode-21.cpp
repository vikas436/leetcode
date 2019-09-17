// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* head,*ptr;
        if(l1->val<l2->val) {
            head=l1;
            l1=l1->next;
        } else {
            head=l2;
            l2=l2->next;
        }
        ptr=head;
        while(l1!=NULL && l2!=NULL) {
            if(l1->val<l2->val) {
                head->next = l1;
                l1=l1->next;
            }else {
                head->next = l2;
                l2=l2->next;
            }
            head = head->next;
        }
        if(l1!=NULL) head->next = l1;
        if(l2!=NULL) head->next = l2;
        return ptr;
    }
};

// 25. Reverse Nodes in k-Group

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
    ListNode* reverseList(ListNode* head, int k) {
        ListNode *cur=head,*next=NULL, *pre=NULL, *ptr=cur;
        int cnt=0;
        while(cur!=NULL && cnt<k) {
            next = cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            cnt++;
        }
        if(cnt!=k) {
            cur=head;
            while(cur!=NULL) {
                next = cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
            }
        }
        ptr->next = reverseKGroup(cur ,k);
        return pre;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        if(k==1) return head;
        int cnt=0;
        ListNode* cur = head;
        while(cur!=NULL) {
            cnt++;
            cur=cur->next;
        }
        if(cnt<k) return head;
        return reverseList(head, k);
    }
};

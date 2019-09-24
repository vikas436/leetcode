// 61. Rotate List

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
    int size(ListNode* head) {
        int len=0;
        while(head!=NULL) {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* move(ListNode* head) { 
        if(head==NULL) return head;
        ListNode *pre=NULL;
        while(head!=NULL) {
            pre=head;
            head=head->next;
        }
        return pre;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = size(head);
        if(k==0 || head==NULL || head->next==NULL || len==k || k%len==0) return head;
        k=k%len;
        int sz = len-k;
        if(len<=k) {
            len=k-len;
            sz=size(head)-len;
        }
        ListNode *cur=head,*pre=NULL,*res=NULL;
        while(sz>0) {
            pre=cur;
            cur=cur->next;
            sz--;
        }
        res = pre->next;
        pre->next=NULL;
        pre = move(cur);
        pre->next = head;
        return res;
    }
};

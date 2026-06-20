/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        if(head->next==NULL){
            return NULL;
        }
        while(temp){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        if(cnt-n==0){
            head=head->next;
            return head;
        }
        int it=1;
        ListNode* prev=head;
        ListNode* curr=NULL;
        while(it<cnt-n){
            it++;
            prev=prev->next;
        }
        curr=prev->next;
        ListNode* nextnode=curr->next;
        prev->next=nextnode;
        return head;
    }
};

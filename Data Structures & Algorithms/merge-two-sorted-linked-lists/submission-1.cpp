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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* temp=list1;
        if(list1==NULL && list2==NULL){
            return list1;
        }
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=list2;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        int n=v.size();
        ListNode* head=new ListNode(v[0]);
        temp=head;
        for(int i=1;i<n;i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        } 
        return head;
    }
};

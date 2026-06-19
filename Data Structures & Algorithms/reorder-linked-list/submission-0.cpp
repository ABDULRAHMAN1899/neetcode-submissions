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
    void reorderList(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        vector<int> res;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            if(i==j){
                res.push_back(ans[i]);
            }
            else{
                res.push_back(ans[i]);
                res.push_back(ans[j]);
            }
            i++;
            j--;
        }
        temp=head;
        int idx=0;
        while(temp){
            temp->val=res[idx++];
            temp=temp->next;
        }
    }
};

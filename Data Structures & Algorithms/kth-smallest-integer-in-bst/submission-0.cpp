/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root==NULL){
            return 0;
        }
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                q.push(curr->left);
                }
                if(curr->right){
                q.push(curr->right);
                }
                ans.push_back(curr->val);
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};

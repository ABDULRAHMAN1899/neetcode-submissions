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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fin;
        if(root==NULL){
            return fin;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> ans;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                ans.push_back(q.front()->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            fin.push_back(ans);
        }
        return fin;

    }
};

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
    int maxDepth(TreeNode* root) {
        TreeNode* curr=root;
        if(curr==NULL){
            return 0;
        }
        if(curr->left==NULL && curr->right==NULL){
            return 1;
        }
        int left=0;
        int right=0;
        if(curr->left){
        left=1+maxDepth(curr->left);
        }
        if(curr->right){
        right=1+maxDepth(curr->right);
        }
        return max(left,right);
        

    }
};

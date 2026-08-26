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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag=true;
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;;
        }
        queue<TreeNode*> p1;
        queue<TreeNode*> q1;
        p1.push(p);
        q1.push(q);
        while(!p1.empty() && !q1.empty()){
            TreeNode* curr1=p1.front();
            TreeNode* curr2=q1.front();
            if(curr1->val!=curr2->val){
                return false;
            }
            if((curr1->left && !curr2->left) ||
             (curr1->right && !curr2->right)|| (!curr1->left && curr2->left) ||
             (!curr1->right && curr2->right)){
                return false;
             }
            p1.pop();
            q1.pop();
            if(curr1->left){
                p1.push(curr1->left);
            }
            if(curr1->right){
                p1.push(curr1->right);
            }
            if(curr2->left){
                q1.push(curr2->left);
            }
            if(curr2->right){
                q1.push(curr2->right);
            }
            
        }
        return p1.empty()&&q1.empty();
    }
};

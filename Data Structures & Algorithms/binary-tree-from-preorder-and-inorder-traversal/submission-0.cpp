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

    unordered_map<int, int> mp;

    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,

                    int inStart, int inEnd) {

        if (inStart > inEnd) {

            return NULL;

        }

        // Root is always the current preorder element

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // Find root in inorder

        int inIndex = mp[root->val];

        // Build left subtree

        root->left = build(preorder, inorder, inStart, inIndex - 1);

        // Build right subtree

        root->right = build(preorder, inorder, inIndex + 1, inEnd);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {

            mp[inorder[i]] = i;

        }

        return build(preorder, inorder, 0, inorder.size() - 1);

    }

};

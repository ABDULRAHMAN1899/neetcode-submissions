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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string st="";
        queue<TreeNode*> q;
        if(root==NULL){
            return "";
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                st.append("#,");
            }
            else{
                st.append(to_string(curr->val)+",");
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return st;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return NULL;
        }
        stringstream ss(data);
        string str;

        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr=q.front();
            q.pop();

            getline(ss,str,',');
            if(str !="#"){
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }

            getline(ss,str,',');
            if(str !="#"){
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

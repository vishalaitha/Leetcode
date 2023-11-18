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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // find a node suitable for insertion
        // the condition is that it's left or right based on the current root's value should be null
        if(root==NULL) return new TreeNode(val);
        TreeNode*temp=root;
        helper(root,val);
        return temp;
    }
    void helper(TreeNode*root,int val){
        if(root==NULL){
            cout<<"line 24"<<endl;
            return;
        }
        else{
            if(root->val<val){
                if(root->right==NULL){
                    TreeNode*temp=new TreeNode(val);
                    root->right=temp;
                }
                else{
                    helper(root->right,val);
                }
            }
            else if(root->val>val){
                if(root->left==NULL){
                    TreeNode*temp=new TreeNode(val);
                    root->left=temp;
                }
                else{
                    helper(root->left,val);
                }
            }
        }
    }
};
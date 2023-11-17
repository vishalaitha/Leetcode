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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode*root=builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
    TreeNode* builder(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&inMap){
        if(preStart>preEnd||inStart>inEnd) return NULL;
        TreeNode*current=new TreeNode(preorder[preStart]);
        int indInorder=inMap[current->val];
        int numsLeft=indInorder-inStart;

        current->left=builder(preorder,preStart+1,preStart+numsLeft,inorder,inStart,indInorder-1,inMap);
        current->right=builder(preorder,preStart+numsLeft+1,preEnd,inorder,indInorder+1,inEnd,inMap);
        return current;
    }
};
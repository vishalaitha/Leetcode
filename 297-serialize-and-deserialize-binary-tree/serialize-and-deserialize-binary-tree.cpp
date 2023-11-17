/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL) return "";

        string ans="";
        
        queue<TreeNode*>q;
        q.push(root);

        ans+=to_string(root->val)+',';

        while(!q.empty()){
            
            int sz=q.size();
            for(int i=0;i<sz;i++){

                TreeNode*current=q.front();
                q.pop();
                if(current->left){
                    ans+=to_string(current->left->val)+',';
                    q.push(current->left);
                }
                else{
                    ans+="#,";
                }
                if(current->right){
                    ans+=to_string(current->right->val)+',';
                    q.push(current->right);
                }
                else{
                    ans+="#,";
                }
            }

        }
        // cout<<ans<<endl;
        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode*leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode*rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
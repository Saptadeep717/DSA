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

    TreeNode* LCA(TreeNode* root, int v1, int v2){
        if(!root) return NULL;
        if(root->val == v1 || root->val == v2) return root;
        TreeNode* left = LCA(root->left,v1,v2);
        TreeNode* right = LCA(root->right,v1,v2);

        if(left && right){
            return root;
        }

        return left!=NULL ? left : right;

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;

        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>v;
        while(!q.empty()){
            int size = q.size();
            v.clear();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
        }
        if(v.size()==1) return v.back();
        int val1 = v[0]->val, val2 = v.back()->val;   
        return LCA(root, val1,val2);

    }
};
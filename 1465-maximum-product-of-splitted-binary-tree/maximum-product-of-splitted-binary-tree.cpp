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
    long long mod = 1e9+7;
    long long ans = 0;
    
    long long dfs(TreeNode* node){
        if(!node) return 0;
        return node->val+= dfs(node->left) + dfs(node->right);
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            long long curr = (total - node->val) * node->val;
            ans = max(ans, curr);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return ans % mod;
    }
};
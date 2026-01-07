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
        return node->val + dfs(node->left) + dfs(node->right);
    }

    long long dfsSum(TreeNode* node, int total){
        if(!node) return 0;
        long long sum = node->val + dfsSum(node->left,total) +dfsSum(node->right,total);
        ans = max(ans, (total - sum) * sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        dfsSum(root,total);
        return ans % mod;
    }
};
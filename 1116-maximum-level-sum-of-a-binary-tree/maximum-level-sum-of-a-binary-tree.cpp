/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        int maxi = INT_MIN;
        int ans = 0;
        while (!q.empty()) {

            int size = q.size();
            int sum=0,level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                level = q.front().second;
                sum+=node->val;
                q.pop();           
                if (node->left) {
                    q.push({node->left, level + 1});
                   
                }

                if (node->right) {
                    q.push({node->right, level + 1});
                    
                }
            }

            if (sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }

        return ans;
    }
};
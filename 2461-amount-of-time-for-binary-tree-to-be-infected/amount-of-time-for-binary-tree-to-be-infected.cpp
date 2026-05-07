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
    TreeNode* mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parentTracker, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* n;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == start) n = node;
            q.pop();

            if(node->left){
                parentTracker[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parentTracker[node->right] = node;
                q.push(node->right);
            }
        }
        return n;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parentTracker;
        TreeNode* startNode = mapping(root, parentTracker, start);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(startNode);
        visited[startNode] = 1;
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            time++;
            for(int i =0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    visited[node->left] =1;
                    q.push(node->left);
                }
                 if(node->right && !visited[node->right]){
                    visited[node->right] =1;
                    q.push(node->right);
                }
                 if(parentTracker[node] && !visited[parentTracker[node]]){
                    visited[parentTracker[node]] =1;
                    q.push(parentTracker[node]);
                }
            }
        }
        return time-1;
    }
};
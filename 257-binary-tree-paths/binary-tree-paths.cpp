class Solution {
public:

    void solve(TreeNode* root, string& path, vector<string>& ans) {

        int len = path.size(); // store old length

        path += to_string(root->val);

        // leaf node
        if (!root->left && !root->right) {
            ans.push_back(path);
        }
        else {

            path += "->";

            if (root->left) {
                solve(root->left, path, ans);
            }

            if (root->right) {
                solve(root->right, path, ans);
            }
        }

        // backtrack
        path.resize(len);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string path;

        solve(root, path, ans);

        return ans;
    }
};
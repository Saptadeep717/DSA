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

     TreeNode* constructTree (vector<int>& postorder,int postStart,int postEnd ,vector<int>& inorder, int inStart, int inEnd, map<int,int>&mpp){
        if(postStart< postEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postStart]);
        int inRoot = mpp[root->val];
        // numsRight tells how many nodes before root in postOrder belong to the right subtree basically where the right subtree ends
        int numsRight = inEnd - inRoot;
        root->left = constructTree(postorder,postStart-numsRight-1,postEnd,
                                   inorder,inStart,inRoot-1,mpp);
        root->right = constructTree(postorder,postStart-1,postStart-numsRight,
                                   inorder,inRoot+1,inEnd,mpp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = constructTree(postorder,postorder.size()-1, 0,              
                         inorder,0,inorder.size()-1,inMap);
        return root;
    }
};
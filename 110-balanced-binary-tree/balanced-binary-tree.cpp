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
    int helper(TreeNode* root){
        if(!root)return 0;
        int leftHeight = helper(root->left);
        int rightHeight = helper(root->right);
        if(rightHeight==1e5 || leftHeight==1e5)return 1e5;
        if(abs(leftHeight-rightHeight)>1)return 1e5;
        return 1 + max(leftHeight , rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return (helper(root)==1e5) ? false : true;
    }
};
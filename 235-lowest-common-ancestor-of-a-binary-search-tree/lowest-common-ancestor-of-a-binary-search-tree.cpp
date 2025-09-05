/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        if(root==p||root==q)return root;
        TreeNode* leftCommon = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightCommon = lowestCommonAncestor(root->right,p,q);
        if(leftCommon && rightCommon)return root;
        if(leftCommon)return leftCommon;
        return rightCommon;
    }
};
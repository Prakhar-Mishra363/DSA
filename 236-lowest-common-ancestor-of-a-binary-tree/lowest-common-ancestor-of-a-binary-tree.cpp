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
        if(root==p)return p;
        if(root==q)return q;
        if(root==NULL)return NULL;
        
        TreeNode* leftTree = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightTree = lowestCommonAncestor(root->right,p,q);
        if(leftTree&&rightTree)return root;
        if(leftTree)return leftTree;
        return rightTree;
    }
};
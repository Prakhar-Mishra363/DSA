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
        TreeNode* rightCommon = (p->val > root->val && q->val > root->val) ? lowestCommonAncestor(root->right,p,q):NULL;
        TreeNode* leftCommon = (p->val < root->val && q->val < root->val) ? lowestCommonAncestor(root->left,p,q):NULL;
        if(!rightCommon && !leftCommon)return root;
        if(rightCommon && !leftCommon)return rightCommon;
        return leftCommon;
    }
};
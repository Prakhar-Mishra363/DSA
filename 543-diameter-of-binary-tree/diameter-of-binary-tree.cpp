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
    int res=0;
    int height(TreeNode* root){
        if(!root)return 0;
        int leftHt = height(root->left);
        int rightHt = height(root->right);
        res = max(res,leftHt+rightHt);
        return max(leftHt,rightHt)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res;
    }
};
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
    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot)
            return root == subRoot;
        bool leftSub = helper(root->left, subRoot->left);
        bool rightSub = helper(root->right, subRoot->right);
        return (leftSub && rightSub && root->val == subRoot->val);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL)return false;
        bool isValid = root->val==subRoot->val?helper(root,subRoot):false;
        bool leftSub = isSubtree(root->left,subRoot);
        bool rightSub = isSubtree(root->right,subRoot);
        return (leftSub || rightSub||isValid);
    }
};
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
    int mod = 1e9 + 7;
    int maxProductHelper(TreeNode *root, int totalSum,long &currMaxProduct){
        if(!root)return 0;
        int leftSum = maxProductHelper(root->left,totalSum,currMaxProduct);
        int rightSum = maxProductHelper(root->right,totalSum,currMaxProduct);
        long currentSubtreeSum = leftSum + rightSum + root->val;
        currMaxProduct = max(currMaxProduct,(long)((totalSum - currentSubtreeSum))  * currentSubtreeSum);
        // currMaxProduct %= mod;
        return currentSubtreeSum ;
    }
    int calculateSum(TreeNode* root){
        if(!root)return 0;
        int leftSum = calculateSum(root->left);
        int rightSum = calculateSum(root->right);
        return (leftSum + rightSum + root->val);
    }
    int maxProduct(TreeNode* root) {
        int totalSum = calculateSum(root);
        long calculatedMaxProduct = INT_MIN;
        maxProductHelper(root,totalSum,calculatedMaxProduct);
        return calculatedMaxProduct % mod;
    }
};
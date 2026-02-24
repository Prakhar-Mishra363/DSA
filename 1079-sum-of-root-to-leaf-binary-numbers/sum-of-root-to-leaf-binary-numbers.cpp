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
    int helper(TreeNode* root , string s){
        if(!root)return 0;
        if(!root->left && !root->right && root){
            int curr_base=1 , num=0;
            s += root->val + '0';
            for(int idx=s.size()-1 ; idx>=0 ; idx--){
                num += (s[idx]=='1') ? curr_base : 0 ;
                curr_base *= 2;
            }
            return num;
        }
        s += root->val + '0';
        int leftSum = helper(root->left , s);
        int rightSum = helper(root->right , s);
        return leftSum+rightSum;
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root , "");
    }
};
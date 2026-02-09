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
    TreeNode* buildTree(int left , int right , vector<int> &arr){
        if(left>right)return nullptr;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(left , mid-1 , arr);
        root->right = buildTree(mid+1 , right , arr);
        return root;
    }
    void traversel(TreeNode* root , vector<int> &arr){
        if(!root)return;
        traversel(root->left,arr);
        arr.push_back(root->val);
        traversel(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inOrder;
        traversel(root , inOrder);
        //building the tree
        return buildTree(0 , inOrder.size()-1 , inOrder);
    }
};
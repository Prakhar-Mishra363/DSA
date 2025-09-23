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
    TreeNode* inorderSucc(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key){//key is in the left
            root->left = deleteNode(root->left,key);
        }else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }else{
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right && root->left){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else{
                TreeNode* succ = inorderSucc(root->right);
                root->val = succ->val;
                root->right =  deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};
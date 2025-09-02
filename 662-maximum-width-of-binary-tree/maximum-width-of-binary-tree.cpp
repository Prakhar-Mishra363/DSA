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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;//node,CBT indexing
        q.push({root,0});
        unsigned long long ans=0;
        while(!q.empty()){
            unsigned long long  start=q.front().second,end=q.back().second;
            ans = max(ans,end-start+1);
            int currSize=q.size();
            for(int i=0;i<currSize;i++){
                TreeNode* currNode = q.front().first;
                unsigned long long idx = q.front().second;
                q.pop();
                if(currNode->left){
                    q.push({currNode->left,2*idx+1});
                }
                if(currNode->right){
                    q.push({currNode->right,2*idx+2});
                }
            }
        }
        return ans;
    }
};
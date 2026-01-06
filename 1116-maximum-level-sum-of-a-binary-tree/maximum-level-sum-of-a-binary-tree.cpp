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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        // q.push(NULL);
        int result = INT_MIN;
        int maxLvl = 1,count = 0;
        while(!q.empty()){
            count++;
            int currentLvlsSum = 0;
            int currLvlSize = q.size();
            for(int i=0;i<currLvlSize;i++){
                TreeNode* node = q.front();
                q.pop();
                currentLvlsSum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(result < currentLvlsSum){
                result = currentLvlsSum;
                maxLvl = count;
            }
        }
        return maxLvl;
    }
};
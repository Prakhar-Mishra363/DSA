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
    TreeNode* findingLCA(TreeNode* root , TreeNode* node1 , TreeNode* node2){
        if(!root)return NULL;
        if(root == node1 || root == node2)return root;
        TreeNode* leftLCA = findingLCA(root->left , node1 , node2);
        TreeNode* rightLCA = findingLCA(root->right , node1 , node2);
        if(leftLCA && rightLCA)return root;
        else if(leftLCA)return leftLCA;
        return rightLCA;
    }
    void findingNodesAtLowDepth(TreeNode* root , int depth , vector<TreeNode*> &nodes){
        if(!root)return;
        if(depth == 1){
            nodes.push_back(root);
            return;
        }
        findingNodesAtLowDepth(root->left , depth - 1 , nodes);
        findingNodesAtLowDepth(root->right , depth - 1 , nodes);
    }
    int calculateDepth(TreeNode* root){
        if(!root)return 0;
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
        return 1+max(leftDepth , rightDepth);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //First determining the height/depth of the tree
        int depth = calculateDepth(root);
        cout<<depth<<endl;
        // finding the nodes at lowestDepth
        vector<TreeNode*>nodes;
        findingNodesAtLowDepth(root , depth , nodes);
        for(auto &a : nodes){
            cout<<a->val<<" ";
        }
        //finding LCA
        while(nodes.size() > 1){
            int n=nodes.size();
            TreeNode* node1 = nodes[n-1];
            TreeNode* node2 = nodes[n-2];
            nodes.pop_back();
            nodes.pop_back();
            TreeNode* commonLCA = findingLCA(root , node1 , node2);
            nodes.push_back(commonLCA);
        }
        return nodes[0];
    }
};
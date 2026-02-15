/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void traverse(ListNode* head , vector<int> &arr){
        ListNode* tmp=head;
        while(tmp){
            arr.push_back(tmp->val);
            tmp=tmp->next;
        }
    }
    TreeNode* bulidTree(int start , int end , vector<int> &arr){
        if(start>end)return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = bulidTree(start , mid-1 , arr);
        root->right = bulidTree(mid+1 , end , arr);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> trav;
        traverse(head,trav);
        return bulidTree(0 , trav.size()-1 , trav);
    }
};
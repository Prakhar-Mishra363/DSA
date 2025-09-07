/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        if(root->left && root->right){
            q.push(root->left);
            q.push(root->right);
        }else return root;
        while(!q.empty()){
            int currSize = q.size();
            for(int i=0;i<currSize;i++){
               Node* curr = NULL;
               curr = q.front();
               q.pop();
               if(i<currSize-1){
                curr->next = q.front(); 
               }
               if(curr->left)q.push(curr->left);
               if(curr->right)q.push(curr->right);
            }
        }
       return root; 
    }
};
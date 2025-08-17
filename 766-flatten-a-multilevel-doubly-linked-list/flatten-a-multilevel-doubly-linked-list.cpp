/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)return head;
        if((!head->child)&&(!head->next))return head;
        Node* curr=head;
        while(curr){
            if(curr->child){
                Node* nextNode=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=NULL;
                while(curr->next){
                    curr=curr->next;
                }
                if(nextNode){
                    nextNode->prev=curr;
                    curr->next=nextNode;
                }
            }curr=curr->next;
        }
        return head;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
      Node* oldTemp, *newTemp;
      oldTemp=head;
      //created a node for copy of the current head
      Node* newHead = new Node(head->val);  
      //pointed the newTemp to new node
      newTemp=newHead;
      unordered_map<Node*,Node*>m;
      //storing the values corresponding to old and new addresses
      m[oldTemp]=newTemp;
      oldTemp=oldTemp->next;
      while(oldTemp!=NULL){
        Node* node = new Node(oldTemp->val);
        newTemp->next=node;
        m[oldTemp]=node;
        oldTemp=oldTemp->next;
        newTemp=newTemp->next;
      }
      newTemp=newHead;
      oldTemp=head;
      while(oldTemp){
        if(oldTemp->random){
            newTemp->random=m[oldTemp->random];
        }
        oldTemp=oldTemp->next;
        newTemp=newTemp->next;
      }

      return newHead;
    }
};
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
class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        int count=0;
        ListNode* temp=head;
        //whether K nodes exits or not
        while(count<k){
            if(temp==NULL)return head;
            count++;
            temp=temp->next;
        }
        ListNode* returnedNode=reverse(temp,k);
        temp=head;
        count=0;
        while(count<k){
            count++;
            ListNode* toBeRever=temp;
            temp=temp->next;
            toBeRever->next=returnedNode;
            returnedNode=toBeRever;
        }
        return returnedNode;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};
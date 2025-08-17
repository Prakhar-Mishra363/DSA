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
    ListNode* reversePairs(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(count<2){
            if(temp==NULL)return head;
            temp=temp->next;
            count++;
        }
        //node where reversed node will be attached/swapped;
        ListNode* node=reversePairs(temp);
        count=0;
        temp=head;
        while(count<2){
            count++;
            ListNode* temp1=temp;
            temp=temp->next;
            temp1->next=node;
            node=temp1;
        }return node;
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        return reversePairs(head);
    }
};
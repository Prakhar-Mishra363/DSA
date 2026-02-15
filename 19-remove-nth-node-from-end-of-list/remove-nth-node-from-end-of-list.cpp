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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode* tmp=head;
        while(tmp){
            sz++;
            tmp = tmp->next;
        }
        sz=sz-n;
        if(sz==0)return head->next;
        tmp=head;
        while(sz>1){
            sz--;
            tmp = tmp->next;
        }
        ListNode* toBeDel = tmp->next;
        tmp->next = tmp->next->next;
        delete toBeDel;
        return head;
    }
};
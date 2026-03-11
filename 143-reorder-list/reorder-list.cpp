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
    bool helper(ListNode* &head , ListNode* temp){
        if(temp==nullptr)return false;
        if(helper(head , temp->next)) return true;
        if(head == temp || head->next == temp){
            temp->next = nullptr;
            return true;;
        }
        temp->next=head->next;
        head->next=temp;
        // temp->next=nullptr;
        head = head->next->next;
        return false;
    }
    void reorderList(ListNode* head) {
        helper(head , head);
    }
};
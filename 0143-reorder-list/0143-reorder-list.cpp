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
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        ListNode* prev = NULL;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow->next = NULL;

        ListNode* head1 = head;
        ListNode* head2 = prev;

        while(head2){
            ListNode* nxt = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = nxt;
        }
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0 , head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr != nullptr){
            if(curr->next != nullptr && curr->val == curr->next->val){
                int dup_val = curr->val;
                while(curr != nullptr && curr->val == dup_val){
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
                prev->next = curr;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
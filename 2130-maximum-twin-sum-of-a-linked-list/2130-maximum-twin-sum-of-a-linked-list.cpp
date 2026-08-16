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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* new_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = new_node;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverse(slow);
        ListNode* firstHalf = head;
        int max_sub = 0;
        while(secondHalf != nullptr){
            int current_sum = firstHalf->val + secondHalf->val;
            if(current_sum > max_sub){
                max_sub = current_sum;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return max_sub;
    }
};
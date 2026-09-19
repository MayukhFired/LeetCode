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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHead(0);
        ListNode greatHead(0);

        ListNode* lessTail = &lessHead;
        ListNode* greatTail = &greatHead;

        ListNode* curr = head;

        while(curr != nullptr){
            if(curr->val < x){
                lessTail->next = curr;
                lessTail = lessTail->next;
            }else{
                greatTail->next = curr;
                greatTail = greatTail->next;
            }
            curr = curr->next;
        }
        greatTail->next = NULL;
        lessTail->next = greatHead.next;
        return lessHead.next;
    }
};
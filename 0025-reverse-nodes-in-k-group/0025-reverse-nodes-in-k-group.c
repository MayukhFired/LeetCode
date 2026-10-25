/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* curr , struct ListNode* end){
    struct ListNode* prev = NULL;
    while(curr != end){
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head == NULL){
        return NULL;
    }

    struct ListNode* tail = head;
    for(int i = 0; i < k; i++){
        if(!tail){
            return head;
        }
        tail = tail->next;
    }

    struct ListNode* newHead = reverse(head , tail);
    head->next = reverseKGroup(tail , k);
    return newHead;
}
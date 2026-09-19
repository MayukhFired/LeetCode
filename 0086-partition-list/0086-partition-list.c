/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode lessHead;
    struct ListNode greatHead;

    struct ListNode* lessTail = &lessHead;
    struct ListNode* greatTail = &greatHead;

    struct ListNode* curr = head;
    while(curr != NULL){
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* evenstart = head->next;
    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    return head;
}
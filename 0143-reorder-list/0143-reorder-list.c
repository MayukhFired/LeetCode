/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if(!head){
        return;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;

    while(curr){
        struct ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    slow->next = NULL;

    struct ListNode* head1 = head;
    struct ListNode* head2 = prev;

    while(head2){
        struct ListNode* nxt = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = nxt;
    }
}
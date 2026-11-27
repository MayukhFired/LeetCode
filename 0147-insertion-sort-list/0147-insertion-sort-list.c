/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* curr = head;

    while(curr != NULL) {
        struct ListNode* prev = dummy;
        while(prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        struct ListNode* next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }

    return dummy->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while(curr != NULL){
        struct ListNode* new_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = new_node;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* firstHalf = head;
    struct ListNode* secondHalf = reverse(slow);
    int maxSub = 0;

    while(secondHalf != NULL){
        int current_sum = firstHalf->val + secondHalf->val;
        if(current_sum > maxSub){
            maxSub = current_sum;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return maxSub;
}
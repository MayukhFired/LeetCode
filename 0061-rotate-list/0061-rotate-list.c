/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || !head->next || k == 0){
        return head;
    }

    int length = 1;
    struct ListNode* tail = head;
    while(tail->next){
        tail = tail->next;
        length++;
    }

    k = k % length;
    if(k == 0){
        return head;
    }
    
    tail->next = head;

    int stepsNew = length - k - 1;
    struct ListNode* new_tail = head;
    for(int i = 0; i < stepsNew; i++){
        new_tail = new_tail->next;
    }

    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}
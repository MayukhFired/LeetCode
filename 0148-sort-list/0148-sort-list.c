/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* split(struct ListNode* head , int step){
    if(!head){
        return NULL;
    }

    for(int i = 1; head->next && i < step; i++){
        head = head->next;
    }

    struct ListNode* rest = head->next;
    head->next = NULL;
    return rest;
}

struct ListNode* merge(struct ListNode* l1 , struct ListNode* l2 , struct ListNode** tail){
    struct ListNode dummy;
    struct ListNode* curr = &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            curr->next = l1;
            l1 = l1->next;
        }else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    while(curr->next){
        curr = curr->next;
    }

    *tail = curr;
    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(!head || !head->next){
        return head;
    }

    int length = 0;
    struct ListNode* curr = head;
    while(curr){
        length++;
        curr = curr->next;
    }

    struct ListNode dummy;
    dummy.next = head;
    for(int i = 1; i < length; i *= 2){
        struct ListNode* prev = &dummy;
        curr = dummy.next;

        while(curr){
            struct ListNode* h1 = curr;
            struct ListNode* h2 = split(h1 , i);
            curr = split(h2 , i);

            struct ListNode* tail = NULL;
            prev->next = merge(h1 , h2 , &tail);
            prev = tail;
        }
    }
    return dummy.next;
}
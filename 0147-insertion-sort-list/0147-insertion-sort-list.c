/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int compare(const void* a , const void* b) {
    return (*(int*)a - *(int*)b);
}

struct ListNode* insertionSortList(struct ListNode* head) {
// 1-----------------------------------------------------------------------------------1
    // struct ListNode* dummy = malloc(sizeof(struct ListNode));
    // dummy->next = NULL;
    // struct ListNode* curr = head;

    // while(curr != NULL) {
    //     struct ListNode* prev = dummy;
    //     while(prev->next != NULL && prev->next->val < curr->val) {
    //         prev = prev->next;
    //     }

    //     struct ListNode* next = curr->next;
    //     curr->next = prev->next;
    //     prev->next = curr;
    //     curr = next;
    // }

    // return dummy->next;
// 1-----------------------------------------------------------------------------------1
    if(head == NULL) return NULL;
    struct ListNode* it = head;
    int count = 0;
    while(it != NULL) {
        count++;
        it = it->next;
    }

    int* arr = (int*)malloc(count * sizeof(int));
    it = head;
    for(int i = 0; i < count; i++) {
        arr[i] = it->val;
        it = it->next;
    }

    qsort(arr , count , sizeof(int) , compare);
    it = head;
    for(int i = 0; i < count; i++) {
        it->val = arr[i];
        it = it->next;
    }

    free(arr);
    return head;
}
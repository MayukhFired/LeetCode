/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwo(struct ListNode* l1 , struct ListNode* l2){
    struct ListNode dummy;
    struct ListNode* curr = &dummy;
    dummy.next = NULL;

    while(l1 && l2){
        if(l1->val <= l2->val){
            curr->next = l1;
            l1 = l1->next;
        }else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(listsSize == 0 || lists == NULL){
        return NULL;
    }

    int interval = 1;
    while(interval < listsSize){
        for(int i = 0; i < listsSize - interval; i += interval * 2){
            lists[i] = mergeTwo(lists[i] , lists[i + interval]);
        }
        interval *= 2;
    }
    return lists[0];
}
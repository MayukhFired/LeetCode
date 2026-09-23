/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* split(struct ListNode* head , int step){
//     if(!head){
//         return NULL;
//     }

//     for(int i = 1; head->next && i < step; i++){
//         head = head->next;
//     }

//     struct ListNode* rest = head->next;
//     head->next = NULL;
//     return rest;
// }

// struct ListNode* merge(struct ListNode* l1 , struct ListNode* l2 , struct ListNode** tail){
//     struct ListNode dummy;
//     struct ListNode* curr = &dummy;

//     while(l1 && l2){
//         if(l1->val < l2->val){
//             curr->next = l1;
//             l1 = l1->next;
//         }else{
//             curr->next = l2;
//             l2 = l2->next;
//         }
//         curr = curr->next;
//     }
//     curr->next = l1 ? l1 : l2;
//     while(curr->next){
//         curr = curr->next;
//     }

//     *tail = curr;
//     return dummy.next;
// }

// struct ListNode* sortList(struct ListNode* head) {
//     if(!head || !head->next){
//         return head;
//     }

//     int length = 0;
//     struct ListNode* curr = head;
//     while(curr){
//         length++;
//         curr = curr->next;
//     }

//     struct ListNode dummy;
//     dummy.next = head;
//     for(int i = 1; i < length; i *= 2){
//         struct ListNode* prev = &dummy;
//         curr = dummy.next;

//         while(curr){
//             struct ListNode* h1 = curr;
//             struct ListNode* h2 = split(h1 , i);
//             curr = split(h2 , i);

//             struct ListNode* tail = NULL;
//             prev->next = merge(h1 , h2 , &tail);
//             prev = tail;
//         }
//     }
//     return dummy.next;
// }

struct ListNode* merge(struct ListNode* l1 , struct ListNode* l2){
    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;

    if(l1->val < l2->val){
        result = l1;
        tail = result;
        l1 = l1->next;
    }else{
        result = l2;
        tail = result;
        l2 = l2->next;
    }

    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    if(l1 != NULL){
        tail->next = l1;
    }else{
        tail->next = l2;
    }
    return result;
}

struct ListNode* mergeSort(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    struct ListNode* l1 = head;
    struct ListNode* l2 = slow;

    l1 = mergeSort(l1);
    l2 = mergeSort(l2);

    return merge(l1 , l2);
}

struct ListNode* sortList(struct ListNode* head){
    return (mergeSort(head));
}
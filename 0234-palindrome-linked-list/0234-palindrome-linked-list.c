/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    // 1-------------------------------------------------1
    // int* arr = (int*)malloc(100001 * sizeof(int));
    // int idx = 0;

    // while(head){
    //     arr[idx++] = head->val;
    //     head = head->next;
    // }

    // int low = 0;
    // int high = idx - 1;
    // while(low < high){
    //     if(arr[low] != arr[high]){
    //         return false;
    //     }
    //     low++;
    //     high--;
    // }
    // return true;
    // 1----------------------------------------------------1

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* temp = slow;

    if(head == NULL || head->next == NULL){
        return true;
    }

    while(fast && fast->next){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast){
        slow = slow->next;
    }

    temp->next = reverse(slow);
    slow = head;
    fast = temp->next;

    while(fast){
        if(fast->val != slow->val){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
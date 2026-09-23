/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode* result = NULL;
        ListNode* tail = NULL;

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

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode* l1 = head;
        ListNode* l2 = slow;

        l1 = mergeSort(l1);
        l2 = mergeSort(l2);

        return merge(l1 , l2);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
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
//This structure is included into the priority queue concept to solve
struct compare{
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public: 
    //This is the solution which uses Divide and Conquer rule to solve this question 
    //ListNode* mergeTwo(ListNode* l1 , ListNode* l2){
    //     ListNode dummy;
    //     ListNode* curr = &dummy;
    //     dummy.next = NULL;

    //     while(l1 && l2){
    //         if(l1->val <= l2->val){
    //             curr->next = l1;
    //             l1 = l1->next;
    //         }else{
    //             curr->next = l2;
    //             l2 = l2->next;
    //         }
    //         curr = curr->next;
    //     }
    //     curr->next = l1 ? l1 : l2;
    //     return dummy.next;
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     if(lists.empty()){
    //         return NULL;
    //     }

    //     int interval = 1;
    //     while(interval < lists.size()){
    //         for(int i = 0; i < lists.size() - interval; i += interval * 2){
    //             lists[i] = mergeTwo(lists[i] , lists[i + interval]);
    //         }
    //         interval *= 2;
    //     }
    //     return lists[0];
    
    //This code uses priority queue to solve teh problem 
        priority_queue<ListNode* , vector<ListNode*> , compare> min_heap;

        for(ListNode* root : lists){
            if(root != NULL){
                min_heap.push(root);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!min_heap.empty()){
            ListNode* node = min_heap.top();
            min_heap.pop();

            curr->next = node;
            curr = curr->next;

            if(node->next != NULL){
                min_heap.push(node->next);
            }
        }
        ListNode* head = dummy->next;
        delete(dummy);
        return head;
    }
};
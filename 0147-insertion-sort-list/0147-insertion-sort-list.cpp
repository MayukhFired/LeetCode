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
    ListNode* insertionSortList(ListNode* head) {
    // 1--------------------------------------------------------------------------1
        // ListNode* dummy = new ListNode();
        // ListNode* curr = head;

        // while(curr != NULL) {
        //     ListNode* prev = dummy;
        //     while(prev->next != NULL && prev->next->val <= curr->val) {
        //         prev = prev->next;
        //     }
        //     ListNode* next = curr->next;
        //     curr->next = prev->next;
        //     prev->next = curr;
        //     curr = next;
        // }

        // return dummy->next;
    // 1----------------------------------------------------------------------------1
        vector<int> arr;
        ListNode* it = head;
        while(it != NULL) {
            arr.push_back(it->val);
            it = it->next;
        }
        sort(arr.begin() , arr.end());
        it = head;
        for(auto i : arr) {
            it->val = i;
            it = it->next;
        }
        return head;
    }
};
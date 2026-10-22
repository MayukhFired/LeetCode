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
private:
    struct ListNode* reverse(ListNode* head){
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
    // 1-------------------------------------1
        // vector<int> arr;
        // while(head){
        //     arr.push_back(head->val);
        //     head = head->next;
        // }

        // int low = 0;
        // int high = arr.size() - 1;
        // while(low < high){
        //     if(arr[low] != arr[high]){
        //         return false;
        //     }
        //     low++;
        //     high--;
        // }
        // return true;
    // 1---------------------------------------1

        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = slow;

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
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
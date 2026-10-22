/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int* arr = (int*)malloc(100001 * sizeof(int));
    int idx = 0;

    while(head){
        arr[idx++] = head->val;
        head = head->next;
    }

    int low = 0;
    int high = idx - 1;
    while(low < high){
        if(arr[low] != arr[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}
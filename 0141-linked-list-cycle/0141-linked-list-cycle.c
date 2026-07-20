// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// bool hasCycle(struct ListNode *head) {

//     if(head == NULL){
//         return false;
//     }
//     struct ListNode *slow = head;
//     struct ListNode *fast = head;

//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow == fast){
//             return true;
//         }
//     }

//     return false;
// }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    if(head == NULL)
        return 0;
    do{
        if(fast->next == NULL || fast->next->next == NULL)
            return 0;
            fast = fast->next->next;
            slow = slow->next;
    }while(fast!=slow);
    return 1;
}
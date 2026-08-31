/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    int minDistance = INT_MAX;

    struct ListNode* previousNode = head;
    struct ListNode* currentNode = head->next;
    int currentIndex = 1;
    int pCIndex = 0;
    int fCIndex = 0;

    while(currentNode->next != NULL){
        if((currentNode->val < previousNode->val && currentNode->val <currentNode->next->val) || (currentNode->val > previousNode->val && currentNode->val > currentNode->next->val)){
            if(pCIndex == 0){
                pCIndex = currentIndex;
                fCIndex = currentIndex;
            }else{
                minDistance = fmin(minDistance , currentIndex - pCIndex);
                pCIndex = currentIndex;
            }
        }
        currentIndex++;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if(pCIndex != fCIndex){
        result[0] = minDistance;
        result[1] = pCIndex - fCIndex;
    }
    return result;
}
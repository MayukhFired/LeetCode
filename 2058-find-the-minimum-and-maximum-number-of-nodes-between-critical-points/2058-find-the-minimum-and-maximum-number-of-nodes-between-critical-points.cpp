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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result = {-1 , -1};
        int minDistance = INT_MAX;
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentIndex = 1;
        int pCIndex = 0;
        int fCIndex = 0;
        while(currentNode->next != nullptr){
            if((currentNode->val < previousNode->val && currentNode->val < currentNode->next->val) || (currentNode->val > previousNode->val && currentNode->val > currentNode->next->val)){
                if(pCIndex == 0){
                    pCIndex = currentIndex;
                    fCIndex = currentIndex;
                }else{
                    minDistance = min(minDistance , currentIndex - pCIndex);
                    pCIndex = currentIndex;
                }
            }
            currentIndex++;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if(minDistance != INT_MAX){
            int maxDistance = pCIndex - fCIndex;
            result = {minDistance , maxDistance};
        }
        return result;
    }
};
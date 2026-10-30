/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	if(!head){
        return NULL;
    }

    struct Node* curr = head;

    while(curr){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->val = curr->val;
        new_node->next = curr->next;
        new_node->random = NULL;
        curr->next = new_node;
        curr = new_node->next;
    }

    curr = head;
    while(curr){
        if(curr->random){
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    struct Node* old_head = head;
    struct Node* new_head = head->next;
    struct Node* curr_old = old_head;
    struct Node* curr_new = new_head;

    while(curr_old){
        curr_old->next = curr_old->next->next;
        curr_new->next = curr_new->next ? curr_new->next->next : NULL;
        curr_old = curr_old->next;
        curr_new = curr_new->next;
    }

    return new_head;
}
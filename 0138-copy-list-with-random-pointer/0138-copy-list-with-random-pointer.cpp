/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    // 1--------------------------------------------------------------------1
        // if(!head){
        //     return nullptr;
        // }

        // Node* curr = head;
        // while(curr){
        //     Node* new_node = new Node(curr->val);
        //     new_node->next = curr->next;
        //     curr->next = new_node;
        //     curr = new_node->next;
        // }

        // curr = head;
        // while(curr){
        //     if(curr->random){
        //         curr->next->random = curr->random->next;
        //     }
        //     curr = curr->next->next;
        // }

        // Node* old_head = head;
        // Node* new_head = head->next;
        // Node* curr_old = old_head;
        // Node* curr_new = new_head;

        // while(curr_old){
        //     curr_old->next = curr_old->next->next;
        //     curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
        //     curr_old = curr_old->next;
        //     curr_new = curr_new->next;
        // }

        // return new_head;
    // 1------------------------------------------------------------------------------1

        if(!head){
            return nullptr;
        }

        unordered_map<Node* , Node*> old_to_new;
        Node* curr = head;
        while(curr){
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next;
        }

        return old_to_new[head];
    }
};
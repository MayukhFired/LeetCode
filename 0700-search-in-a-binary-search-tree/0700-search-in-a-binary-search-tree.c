/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* current = root;
    while(current != NULL && current->val != val){
        if(val < current->val){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}
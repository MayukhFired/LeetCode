/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* findMin(struct TreeNode* node){
    struct TreeNode* current = node;
    while(current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root == NULL){
        return NULL;
    }
    if(key < root->val){
        root->left = deleteNode(root->left , key);
    }else if(key > root->val){
        root->right = deleteNode(root->right , key);
    }else{
        if(root->left == NULL){
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }else{
            struct TreeNode* s = findMin(root->right);
            root->val = s->val;
            root->right = deleteNode(root->right , s->val);
        }
    }
    return root;
}
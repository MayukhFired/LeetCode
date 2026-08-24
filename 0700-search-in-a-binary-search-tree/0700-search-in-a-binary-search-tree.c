/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    //Iterative Method
    // struct TreeNode* current = root;
    // while(current != NULL && current->val != val){
    //     if(val < current->val){
    //         current = current->left;
    //     }else{
    //         current = current->right;
    //     }
    // }
    // return current;
    //Recursive Method
    if(root == NULL || root->val == val){
        return root;
    }
    if(root->val > val){
        return searchBST(root->left , val);
    }
    return searchBST(root->right , val);
}
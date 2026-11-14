/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode* node , int** res , int* returnSize , int* capacity){
    if(!node){
        return;
    }

    inorder(node->left , res , returnSize ,capacity);
    if(*returnSize >= *capacity){
        *capacity *= 2;
        *res = (int*)realloc(*res , (*capacity)* sizeof(int));
    }

    (*res)[(*returnSize)++] = node->val;
    inorder(node->right , res , returnSize , capacity);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(!root){
        return NULL;
    }

    int capacity = 16;
    int* res = (int*)malloc(capacity * sizeof(int));
    inorder(root , &res , returnSize , &capacity);
    return res;
}
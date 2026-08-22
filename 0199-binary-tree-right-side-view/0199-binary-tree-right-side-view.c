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
// int getHeight(struct TreeNode* root){
//     if(!root){
//         return 0;
//     }
//     int leftHeight = getHeight(root->left);
//     int rightHeight = getHeight(root->right);
//     return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
// }
// void dfs(struct TreeNode* node , int depth , int* result , int* filledLevels){
//     if(!node){
//         return;
//     }
//     if(depth == *filledLevels){
//         result[depth] = node->val;
//         (*filledLevels)++;
//     }

//     dfs(node->right , depth + 1 , result , filledLevels);
//     dfs(node->left , depth + 1 , result , filledLevels);
// }
// int* rightSideView(struct TreeNode* root, int* returnSize) {
//     int height = getHeight(root);
//     *returnSize = height;
//     if(height == 0){
//         return 0;
//     }
//     int* result = (int*)malloc(height * sizeof(int));
//     int filledLevels = 0;
//     dfs(root , 0 , result , &filledLevels);
//     return result;
// }
int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(!root){
        return NULL;
    }
    int capacity = 10;
    int* result = (int*)malloc(capacity * sizeof(int));
    int maxsize = 10000;
    struct TreeNode** queue = (struct TreeNode**)malloc(maxsize * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;
    queue[tail++] = root;
    while(head < tail){
        int levelSize = tail - head;
        for(int i = 0; i < levelSize; i++){
            struct TreeNode* curr = queue[head++];
            if(i == levelSize - 1){
                if(*returnSize >= capacity){
                    capacity *= 2;
                    result = (int*)realloc(result , capacity * sizeof(int));
                }
                result[(*returnSize)++] = curr->val;
            }
            if(curr->left && tail < maxsize) queue[tail++] = curr->left;
            if(curr->right && tail < maxsize) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return result;
}
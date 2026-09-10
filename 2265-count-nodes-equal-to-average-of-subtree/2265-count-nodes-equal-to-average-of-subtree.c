/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct{
    int sum;
    int count;
}SubResult;

SubResult dfs(struct TreeNode* node , int* resultCount){
    SubResult res = {0 , 0};
    if(node == NULL){
        return res;
    }

    SubResult leftres = dfs(node->left , resultCount);
    SubResult rightres = dfs(node->right , resultCount);

    res.sum = leftres.sum + rightres.sum + node->val;
    res.count = leftres.count + rightres.count + 1;

    if(res.sum / res.count == node->val){
        (*resultCount)++;
    }

    return res;
}

int averageOfSubtree(struct TreeNode* root) {
    int resultCount = 0;
    dfs(root , &resultCount);
    return resultCount;
}
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9int dfs(struct TreeNode* node , int max_so_far){
10    if(node == NULL){
11        return 0;
12    }
13    int is_good = 0;
14    if(node->val >= max_so_far){
15        is_good = 1;
16        max_so_far = node->val;
17    }
18    int good_right = dfs(node->right , max_so_far);
19    int good_left = dfs(node->left , max_so_far);
20    return is_good + good_right + good_left;
21}
22
23int goodNodes(struct TreeNode* root){
24    if(root == NULL){
25        return 0;
26    }
27    return dfs(root , root->val);
28}
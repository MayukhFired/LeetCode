1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
10    if(root == NULL || root == p || root == q){
11        return root;
12    }
13    struct TreeNode* left = lowestCommonAncestor(root->left , p , q);
14    struct TreeNode* right = lowestCommonAncestor(root->right , p , q);
15    if(left != NULL && right != NULL){
16        return root;
17    }
18    return (left != NULL) ? left : right;
19}
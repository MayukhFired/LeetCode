1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(root == NULL || root == p || root == q){
14            return root;
15        }
16
17        TreeNode* left = lowestCommonAncestor(root->left , p , q);
18        TreeNode* right = lowestCommonAncestor(root->right , p , q);
19        if(left != NULL && right != NULL){
20            return root;
21        }
22        return (left != NULL) ? left : right;
23    }
24};
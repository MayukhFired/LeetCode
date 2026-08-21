1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int dfs(TreeNode* node , int max_so_far){
15        if(node == NULL){
16            return 0;
17        }
18        int is_good = 0;
19        if(node->val >= max_so_far){
20            is_good = 1;
21            max_so_far = node->val;
22        }
23        int good_right = dfs(node->right , max_so_far);
24        int good_left = dfs(node->left , max_so_far);
25        return is_good + good_right + good_left;
26    }
27    int goodNodes(TreeNode* root) {
28        if(root == NULL){
29            return 0;
30        }
31        return dfs(root , root->val);
32    }
33};
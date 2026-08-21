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
14    int CountPath(TreeNode* node , long long current_sum , int targetSum){
15        if(node == NULL){
16            return 0;
17        }
18        int count = 0;
19        current_sum += node->val;
20        if(current_sum == targetSum){
21            count++;
22        }
23
24        count += CountPath(node->left , current_sum , targetSum);
25        count += CountPath(node->right , current_sum , targetSum);
26        return count;
27    }
28    int pathSum(TreeNode* root, int targetSum) {
29        if(root == NULL){
30            return 0;
31        }
32
33        int find_path = CountPath(root , 0 , targetSum);
34        int left_node = pathSum(root->left , targetSum);
35        int right_node = pathSum(root->right , targetSum);
36        return find_path + left_node + right_node;
37    }
38};
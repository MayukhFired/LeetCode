1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     struct TreeNode *left;
6 *     struct TreeNode *right;
7 * };
8 */
9int countFromNode(struct TreeNode* node , long long currentSum , int targetSum){
10    if(node == NULL){
11        return 0;
12    }
13    int count = 0;
14    currentSum += node->val;
15    if(currentSum == targetSum){
16        count++;
17    }
18    count += countFromNode(node->left , currentSum , targetSum);
19    count += countFromNode(node->right , currentSum , targetSum);
20    return count;
21}
22int pathSum(struct TreeNode* root, int targetSum) {
23    if(root == NULL){
24        return 0;
25    }
26    int path_from_root = countFromNode(root , 0 , targetSum);
27    int path_left = pathSum(root->left , targetSum);
28    int path_right = pathSum(root->right , targetSum);
29    return path_from_root + path_left + path_right;
30}
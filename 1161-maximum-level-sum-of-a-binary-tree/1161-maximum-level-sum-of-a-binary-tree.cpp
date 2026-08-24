/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int max_sum = INT_MIN;
        int max_level = 1;
        int current_level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int level_size = q.size();
            int level_sum = 0;
            for(int i = 0; i < level_size; i++){
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(level_sum > max_sum){
                max_sum = level_sum;
                max_level = current_level;
            }
            current_level++;
        }
        return max_level;
    }
};
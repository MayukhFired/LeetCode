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
    TreeNode* searchBST(TreeNode* root, int val) {
        //Iterative Mthod to solve the question 
        // TreeNode* current = root;
        // while(current != NULL && current->val != val){
        //     if(current->val > val){
        //         current = current->left;
        //     }else{
        //         current = current->right;
        //     }
        // }
        // return current;

        //Recursive Method for the problem 
        if(root == NULL || root->val == val){
            return root;
        }
        if(val < root->val){
            return searchBST(root->left , val);
        }
        return searchBST(root->right , val);
    }
};
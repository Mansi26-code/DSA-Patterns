/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // your code goes heret
        if (root == NULL) {
            return new TreeNode(val);
        }
        if (root->data < val) {
            root->right = insertIntoBST(root->right, val);
        } else
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};
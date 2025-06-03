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
    // Function to compute the maximum depth (height) of the binary tree
    int maxDepth(TreeNode* root) {
        // Base case: if the node is null, depth is 0
        if (root == NULL)
            return 0;

        // Recursively compute the depth of left and right subtrees and return the greater one + 1
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Function to check if a binary tree is height-balanced
    bool isBalanced(TreeNode* root) {
        // Base case: an empty tree is always balanced
        if (root == NULL)
            return true;

        // Calculate the height of left and right subtrees
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        // If height difference is more than 1, it's not balanced
        if (abs(leftHeight - rightHeight) > 1)
            return false;

        // Recursively check if left and right subtrees are also balanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
Time Complexity: O(n) Space Complexity: O(h) (where h is the height of the tree)








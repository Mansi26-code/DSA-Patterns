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
    // Helper to calculate leftmost height
    int leftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->left;
            height++;
        }
        return height;
    }

    // Helper to calculate rightmost height
    int rightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int left = leftHeight(root);
        int right = rightHeight(root);

        if (left == right) {
            // Perfect complete tree: nodes = 2^height - 1
            return (1 << left) - 1;
        } else {
            // Not perfect, recurse for left and right subtrees
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};

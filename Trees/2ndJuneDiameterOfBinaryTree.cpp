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
    // Function to compute the height of a subtree rooted at 'root'
    int maxHeight(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxHeight(root->left);
        int right = maxHeight(root->right);

        return 1 + max(left, right);
    }

    // Function to compute the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        // Diameter can be:
        // 1. In the left subtree
        int op1 = diameterOfBinaryTree(root->left);

        // 2. In the right subtree
        int op2 = diameterOfBinaryTree(root->right);

        // 3. Passing through the root node (sum of heights of left and right subtrees)
        int op3 = maxHeight(root->left) + maxHeight(root->right);

        // Return the maximum of the three possible cases
        return max(op1, max(op2, op3));
    }
};
📈 Time and Space Complexity:
Time Complexity: O(n²) — because for each node, you compute the height of its subtrees, leading to repeated work.

Space Complexity: O(h) — where h is the height of the tree, due to recursion stack.




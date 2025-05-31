/*
🔸 Problem: Convert a BST into a Greater Tree.
🔹 For every node, update it to: node's value + sum of all nodes greater than it in the BST.
*/

class Solution {
    int sum = 0; // Keeps track of cumulative sum of nodes visited so far in reverse in-order
public:

    // ✅ Optimized Reverse In-order Traversal: Right -> Node -> Left
    // Time Complexity: O(N) where N is number of nodes
    // Space Complexity: O(H) for recursive stack (H = height of tree)

    TreeNode* bstToGt(TreeNode* root) {
        if (root == NULL) return NULL;

        // Step 1: Traverse right subtree first (greater values)
        bstToGt(root->right);

        // Step 2: Process current node
        sum += root->val;
        root->val = sum;

        // Step 3: Traverse left subtree (smaller values)
        bstToGt(root->left);

        return root;
    }
};

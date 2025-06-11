/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
public:
    // Function to search a value in a BST
    TreeNode* searchBST(TreeNode* root, int val) {
        
        // 🔹 Base Case: If current node is NULL, return NULL (value not found)
        if (root == NULL)
            return NULL;

        // 🔹 If current node's data matches the value, return this node
        if (root->data == val)
            return root;

        // 🔹 If value is smaller than current node's data, search in left subtree
        else if (val < root->data)
            return searchBST(root->left, val);

        // 🔹 If value is greater than current node's data, search in right subtree
        else
            return searchBST(root->right, val);
    }
};


✅ Time and Space Complexity:
Time Complexity (TC):
🔸 Best Case: O(1) → If the root node contains the value.
🔸 Average/Worst Case: O(H) → Where H is the height of the tree.

For a balanced BST, H = log₂N → So, TC = O(log N)

For a skewed BST, H = N → So, TC = O(N)

Space Complexity (SC):
🔸 Due to recursion stack → O(H)

Same logic: O(log N) for balanced BST, O(N) for skewed BST
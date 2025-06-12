class Solution {
  public:

    // 🔸 Function to find the maximum element in a binary tree
    int findMax(Node *root) {
        // 🔹 Base Case: If root is NULL, return smallest possible value
        // So it doesn't affect the max calculation during recursion
        if (root == NULL)
            return INT_MIN;

        // 🔹 Recursive Step:
        // 1. Get the max from left subtree
        // 2. Get the max from right subtree
        // 3. Return the maximum among root's data, left max, and right max
        return max({root->data, findMax(root->left), findMax(root->right)});
    }

    // 🔸 Function to find the minimum element in a binary tree
    int findMin(Node *root) {
        // 🔹 Base Case: If root is NULL, return largest possible value
        // So it doesn't affect the min calculation during recursion
        if (root == NULL)
            return INT_MAX;

        // 🔹 Recursive Step:
        // 1. Get the min from left subtree
        // 2. Get the min from right subtree
        // 3. Return the minimum among root's data, left min, and right min
        return min({root->data, findMin(root->left), findMin(root->right)});
    }
};


time complexity is O(n)
space complexity is O(h)
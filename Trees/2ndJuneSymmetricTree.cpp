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
    // Helper function to compare two subtrees in mirror fashion
    bool check(TreeNode* p, TreeNode* q)
    {
        // Both nodes are null -> symmetric at this point
        if(p == NULL && q == NULL)
            return true;

        // One of them is null -> asymmetric
        if(p == NULL || q == NULL)
            return false;

        // Values mismatch -> not symmetric
        if(p->val != q->val)
            return false;

        // Recursively compare left with right and right with left
        return check(p->left, q->right) && check(p->right, q->left);
    }

    // Main function to check if tree is symmetric
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

/*
🔁 Time Complexity: O(n)
   - Every node is visited once.

🧠 Space Complexity: O(h)
   - Due to recursion stack; h is the height of the tree (O(log n) for balanced, O(n) for skewed).
*/

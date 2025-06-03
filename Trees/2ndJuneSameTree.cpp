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
    // Function to check if two binary trees are structurally identical and node values are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both nodes are NULL -> trees are same at this point
        if(p == NULL && q == NULL)
            return true;

        // Only one is NULL -> trees are different
        if(p == NULL || q == NULL)
            return false;

        // Values at current nodes are different
        if(p->val != q->val)
            return false;

        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
🔁 Time Complexity: O(n)
   - We visit every node exactly once in both trees.

🧠 Space Complexity: O(h)
   - Due to recursion stack, where h is the height of the tree (O(log n) for balanced, O(n) for skewed).
*/

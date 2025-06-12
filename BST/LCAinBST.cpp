/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q) {
        // ✅ Base Case: If root is NULL, return NULL
        if (root == NULL) return NULL;

        // ✅ If root's value lies between p and q (inclusive), it's the LCA
        if (root->data >= min(p, q) && root->data <= max(p, q))
            return root;

        // ✅ If both values are smaller, LCA lies in left subtree
        if (root->data > max(p, q))
            return lca(root->left, p, q);

        // ✅ If both values are greater, LCA lies in right subtree
        return lca(root->right, p, q);
    }
};


//TC & SC= O(h)
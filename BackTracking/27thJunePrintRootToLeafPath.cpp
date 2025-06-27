/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    // Helper function to recursively build all paths
    void solve(TreeNode* root, vector<int>& path, vector<vector<int>>& res) {
        if (root == nullptr)
            return;

        // Add current node to path
        path.push_back(root->data);

        // If it's a leaf node, store the path
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
        } else {
            // Recurse left and right
            solve(root->left, path, res);
            solve(root->right, path, res);
        }

        // Backtrack: remove the last node before returning to parent
        path.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> path;
        solve(root, path, res);
        return res;
    }
};

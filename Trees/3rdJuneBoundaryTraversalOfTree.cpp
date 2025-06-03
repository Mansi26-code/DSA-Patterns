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
    // Helper function to check if a node is a leaf
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    // Traverse the left boundary (excluding leaf nodes)
    void left(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->data); // Replaced val with data
            }

            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Traverse the right boundary (excluding leaf nodes)
    void right(TreeNode* root, vector<int>& res) {
        vector<int> temp; // Temporary vector to store right boundary nodes
        TreeNode* curr = root->right;

        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data); // Replaced val with data
            }

            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Add the right boundary in reverse order
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    // Add all leaf nodes to the result
    void addLeaves(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data); // Replaced val with data
            return;
        }

        if (root->left) {
            addLeaves(root->left, res);
        }
        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    // Main function to return the boundary traversal of the tree
    vector<int> boundary(TreeNode* root) {
        vector<int> res;

        if (!root) return res; // If the tree is empty, return an empty result

        if (!isLeaf(root)) {
            res.push_back(root->data); // Add root to the result if it's not a leaf
        }

        left(root, res);         // Add left boundary
        addLeaves(root, res);    // Add leaf nodes
        right(root, res);        // Add right boundary

        return res;
    }
};


//SC=O(n)
//TC=O(n)
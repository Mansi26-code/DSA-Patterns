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
    vector<int> topView(TreeNode *root) {
        // Result vector to store the top view
        vector<int> res;

        // Edge case: if root is null
        if (root == nullptr) return res;

        // Map to store the first node data at every horizontal distance (column)
        map<int, int> mp;

        // Queue for level order traversal (BFS)
        // Each element: {node, horizontal distance}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int col = it.second;

            // If this column is encountered for the first time, store it
            if (mp.find(col) == mp.end()) {
                mp[col] = node->data;
            }

            // Push left child with column - 1
            if (node->left) {
                q.push({node->left, col - 1});
            }

            // Push right child with column + 1
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }

        // Extracting top view from the map in sorted order of columns
        for (auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};

🧠 Time and Space Complexity:
Time Complexity: O(N log N)

BFS traverses all N nodes → O(N)

Insertion into map is O(log N) per node → O(N log N) overall

Space Complexity: O(N)

For the queue and the map storing at most N nodes
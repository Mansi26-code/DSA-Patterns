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
    vector<int> bottomView(TreeNode *root) {
        // Result vector to store the bottom view
        vector<int> res;

        // Edge case: if tree is empty
        if (root == nullptr) return res;

        // Map to store the latest node at each horizontal distance
        map<int, int> mp;

        // Queue for BFS traversal
        // Each element in queue: {node, horizontal distance}
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second;

            // For bottom view: keep overwriting values for each column
            mp[line] = node->data;

            // Push left child with horizontal distance - 1
            if (node->left) {
                q.push({node->left, line - 1});
            }

            // Push right child with horizontal distance + 1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }

        // Extract bottom view nodes from the map in sorted order of columns
        for (auto it : mp) {
            res.push_back(it.second);
        }

        return res;
    }
};
🧠 Time and Space Complexity:
Time Complexity: O(N log N)

O(N) for BFS traversal of all nodes

O(log N) insertion/update in map for N nodes

Space Complexity: O(N)

Queue holds up to N nodes in the worst case

Map stores one value per horizontal distance, which can be up to N in skewed trees
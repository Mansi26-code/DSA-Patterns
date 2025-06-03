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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Result vector to store vertical traversal
        vector<vector<int>> result;

        // Base case: if root is null, return empty result
        if (root == NULL)
            return result;

        // Map structure to store nodes according to:
        // x-coordinate -> y-coordinate -> min-heap (sorted values)
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> mp;

        // Queue for BFS traversal: stores node along with its (x, y) coordinates
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Initialize BFS with root at position (0, 0)
        q.push({root, {0, 0}});

        // Level-order traversal (BFS)
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;   // vertical level
            int y = p.second.second;  // depth level

            // Push the node's data into the corresponding (x, y) entry in map
            mp[x][y].push(node->data);

            // Traverse left subtree (x - 1, y + 1)
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            // Traverse right subtree (x + 1, y + 1)
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        // Extracting values from the map in required order
        for (auto& p : mp) {  // p = pair<x, map<y, priority_queue>>
            vector<int> col;
            for (auto& q : p.second) {  // q = pair<y, priority_queue>
                while (!q.second.empty()) {
                    col.push_back(q.second.top());
                    q.second.pop();
                }
            }
            result.push_back(col);  // one column done
        }

        return result;
    }
};

Overall TC:
O(N log N)

Overall SC:
O(N)
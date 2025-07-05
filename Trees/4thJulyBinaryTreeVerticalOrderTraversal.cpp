/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // Your code goes here
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> output;
        if (root == NULL) {
            return output;
        }
        map<int, vector<int>> colTable;
        q.push({root, 0});
        while (!q.empty()) {
            auto top = q.front();
            TreeNode* node = top.first;
            int col = top.second;
            q.pop();
            colTable[col].push_back(node->val);
            if (node->left) {
                q.push({node->left, col - 1});
            }
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }

        for (auto& it : colTable) {
            output.push_back(it.second);
        }
        return output;
    }
};

//TC & SC= O(n)
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
    vector<vector<int>> res;

    void solve(TreeNode* root, int targetSum, vector<int>& temp,
               vector<vector<int>>& res) {
        if (root == NULL)
            return;

        temp.push_back(root->val);

        if (!root->left && !root->right && targetSum == root->val) {

            res.push_back(temp);

        } else {

            solve(root->left, targetSum - root->val, temp, res);

            solve(root->right, targetSum - root->val, temp, res);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> temp;
        vector<vector<int>> res;
        solve(root, targetSum, temp, res);
        return res;
    }
};


//TC=O(n*h)
//SC=O(H)

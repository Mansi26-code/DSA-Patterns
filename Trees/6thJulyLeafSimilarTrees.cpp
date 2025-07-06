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
    void addLeafs(TreeNode* root, vector<int>& res) {
        if (!root) return;

        if (!root->left && !root->right) {
            res.push_back(root->val);
        }

        addLeafs(root->left, res);
        addLeafs(root->right, res);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;

        addLeafs(root1, res1);
        addLeafs(root2, res2);

        return res1 == res2;
    }
};


//TC=O(N+M)
//SC=O(H1+H2)
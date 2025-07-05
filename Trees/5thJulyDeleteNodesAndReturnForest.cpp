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
    vector<TreeNode*>result;
    unordered_set<int>to_delete_set;

    TreeNode* dfs(TreeNode* node)
    {  if (!node) return NULL;
        node->left=dfs(node->left);
        node->right=dfs(node->right);

        if(to_delete_set.count(node->val))
        {
            if(node->left)
            result.push_back(node->left);
            if(node->right)
            result.push_back(node->right);

            return NULL;
        }
        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int val:to_delete)
        {
            to_delete_set.insert(val);
        }
        if(dfs(root))
        result.push_back(root);

        return result;
    }
};

//TC=O(n)
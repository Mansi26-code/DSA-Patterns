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

map<int,vector<int>>mp;
int height(TreeNode* root)
{
    if(!root)
    return 0;

    int left=height(root->left);
    int right=height(root->right);

    int H=1+max(left,right);
    mp[H].push_back(root->val);
    return H;
}
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>result;
        height(root);
        for(auto &it:mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
//TC &SC=O(n)
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
string DFS(TreeNode* root, unordered_map<string,int>&mp, vector<TreeNode*>&res)
{
    if(!root)
    return "NULL";

    string s= to_string(root->val)+","+DFS(root->left,mp,res)+","+DFS(root->right,mp,res);

    if(mp[s]==1)
    {
        res.push_back(root);
    }
    mp[s]++;
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string,int>mp;
        DFS(root,mp,res);
        return res;
    }
};

//Complexity	Worst Case	Average Case
Time	O(n²)	O(n log n)
Space	O(n²)	O(n log n)
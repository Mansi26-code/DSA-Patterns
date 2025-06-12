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
TreeNode* solve(vector<int>&preorder, int &i, int maxVal, int minVal)
{
    if(i>=preorder.size()|| preorder[i]>maxVal || preorder[i]<minVal)
    {
        return NULL;
    }
    TreeNode* root=new TreeNode(preorder[i++]);
    root->left=solve(preorder,i,root->val,minVal);
    root->right=solve(preorder,i,maxVal, root->val);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int minVal=INT_MIN;
        int maxVal=INT_MAX;
        int i=0;
        return solve(preorder,i,maxVal,minVal);
    }
};
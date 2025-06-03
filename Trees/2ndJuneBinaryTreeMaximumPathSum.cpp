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
int maxSum=INT_MIN;
int solve(TreeNode* root)
{
    if(root==NULL)
    return 0;

    int left=solve(root->left);
    int right=solve(root->right);
    int any=max(left,right)+root->val;
    int itself=root->val;
    int down=left+right+root->val;

    maxSum=max({maxSum,down,any,itself});
    return max(any,itself);
}
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};
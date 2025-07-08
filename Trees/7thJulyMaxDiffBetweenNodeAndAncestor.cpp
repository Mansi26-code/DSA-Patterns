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
int dfs(TreeNode* root, int minVal,int maxVal)
{
    if(!root)
    
        return maxVal-minVal;

        maxVal=max(maxVal,root->val);
        minVal=min(minVal,root->val);

        int leftVal=dfs(root->left,minVal,maxVal);
        int rightVal=dfs(root->right,minVal,maxVal);
        return max(leftVal,rightVal);
    
}
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
};


//✅ Time Complexity: O(N)
//✅ Space Complexity: O(H), where H = height of tree


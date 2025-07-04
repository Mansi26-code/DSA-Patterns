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
int maxCount=0;

void dfs(TreeNode* node, int parentVal, int currentCount)
{
    if(node==NULL)
    return;

    if(node->val==parentVal+1)
    {
        currentCount++;

    }
    else
    {
        currentCount=1;
    }
    maxCount=max(maxCount,currentCount);
    dfs(node->left,node->val,currentCount);
    dfs(node->right,node->val,currentCount);
}
    int longestConsecutive(TreeNode* root) {
        if(root==NULL)
        return 0;
        dfs(root,root->val-1,0);
        return maxCount;
    }
};


//Time Complexity:O(n), 
//SC=O(h)


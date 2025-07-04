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
int maxLen=0;
pair<int,int>dfs(TreeNode* node)
{
    if(!node)
    return {0,0};

    int inc=1;
    int dec=1;

    if(node->left)
    {
        auto[leftInc,leftDec]=dfs(node->left);

        if(node->val==node->left->val+1)
        {
            dec=leftDec+1;
        }
        else if(node->val==node->left->val-1)
        {
            inc=leftInc+1;
        }
    }

    if(node->right)
    {
        auto[rightInc,rightDec]=dfs(node->right);

        if(node->val==node->right->val+1)
        {
            dec=max(dec,rightDec+1);
        }

        else if(node->val==node->right->val-1)
        {
            inc=max(inc,rightInc+1);
        }
    }
    
    maxLen=max(maxLen,inc+dec-1);

    return {inc,dec};

}
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};


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
int sum=0;

int DFS(TreeNode* root,int sum)
{
    if(root==NULL)
    return 0;

    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL)
    return sum;

    return DFS(root->left,sum)+DFS(root->right,sum);
}
    int sumNumbers(TreeNode* root) {
      return DFS(root,sum);
       
    }
};

✅ Time Complexity: O(N)
✅ Space Complexity: O(H) = O(N) worst case, O(log N) average case
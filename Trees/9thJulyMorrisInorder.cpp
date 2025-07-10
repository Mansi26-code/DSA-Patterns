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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* curr=root;
        TreeNode* pre;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                res.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
              
               pre=curr->left;
               while(pre->right)

               {
                pre=pre->right;
               }
               pre->right=curr;
               TreeNode* temp=curr;
               curr=curr->left;
               temp->left=NULL;

            }
        }
        return res;
    }
};

//TC=O(n)
//SC=O(1)
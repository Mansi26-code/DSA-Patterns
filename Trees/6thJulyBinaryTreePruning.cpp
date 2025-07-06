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

    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
       
       //ye recursiverly root ke left aur right ko check krega
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
  
        //agar current root ki value NULL h, aur root ka left and right dono NULL h
        if(root->val==0 && root->left==NULL &&root->right==NULL)
        return NULL;

        return root;
    }
};
//sc =O(N)
//tc=O(H)

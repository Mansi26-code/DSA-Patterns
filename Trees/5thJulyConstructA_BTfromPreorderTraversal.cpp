/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
TreeNode* solve(vector<int>&preorder, int &i, int maxVal, int minVal)
{
    if(i>=preorder.size() || preorder[i]>maxVal || preorder[i]<minVal)
    return NULL;

    TreeNode* root=new TreeNode(preorder[i++]);
    root->left=solve(preorder,i,root->data,minVal);
    root->right=solve(preorder,i,maxVal,root->data);
    return root;

    
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //your code goes here
        int minVal=INT_MIN;
        int maxVal=INT_MAX;
        int i=0;
       return solve(preorder,i,maxVal,minVal);
    }
};

//TC=O(n)
//SC=O(h)

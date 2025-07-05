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
TreeNode* solve(vector<int>&preorder,vector<int>&inorder, int &idx, int start,int end)
{
    if(start>end)
    return NULL;
    int rootVal=preorder[idx];

    int i=0;
    for(;i<=end;i++)
    {
        if(inorder[i]==rootVal)
        {
            break;
        }
    }
    idx++;
    TreeNode* root=new TreeNode(rootVal);
    root->left=solve(preorder,inorder,idx,start,i-1);
    root->right=solve(preorder,inorder,idx,i+1,end);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here
        int start=0,end=inorder.size()-1;
        int idx=0;
        return solve(preorder,inorder,idx,start,end);
        
    }
};

//tc=o(n^2)
//sc=O(n)
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

TreeNode* addOneRow(TreeNode* root,int val,int depth)
{
    if(depth==1)
    {
        TreeNode* newRoot= new TreeNode(val);
        newRoot->left=root;
        return newRoot;
    }
    insert(root,val,1,depth);
    return root;
}
   
   void insert(TreeNode* node, int val, int currDepth,int targetDepth)
   {
    if(!node)
    return;

    if(currDepth==targetDepth-1)
    {
        TreeNode* leftNew=new TreeNode(val);
        TreeNode* rightNew=new TreeNode(val);

        leftNew->left=node->left;
        rightNew->right=node->right;

        node->left=leftNew;
        node->right=rightNew;
    }
    else
    {
        insert(node->left,val,currDepth+1,targetDepth);
        insert(node->right,val,currDepth+1,targetDepth);
    }
   }
};

//TC=O(N)
//SC=O(H)
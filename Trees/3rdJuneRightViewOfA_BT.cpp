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

void recursion(TreeNode* root, int level, vector<int>&res)
{
    if(root==NULL)
    return;

    if(res.size()==level)
    res.push_back(root->data);

    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);
}
    vector<int> rightSideView(TreeNode* root) {
        //your code goes here
        vector<int>res;
        recursion(root,0,res);
        return res;
    }
};


tc=O(n)
sc=O(h)



//agar left tree ka pucha hoga to 

class Solution {
public:

void recursion(TreeNode* root, int level, vector<int>&res)
{
    if(root==NULL)
    return;

    if(res.size()==level)
    res.push_back(root->data);

     recursion(root->left,level+1,res);
    recursion(root->right,level+1,res);
   
}
    vector<int> rightSideView(TreeNode* root) {
        //your code goes here
        vector<int>res;
        recursion(root,0,res);
        return res;
    }
};


tc=O(n)
sc=O(h)

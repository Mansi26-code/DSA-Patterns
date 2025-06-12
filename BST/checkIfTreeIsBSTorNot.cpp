/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
    bool isBSTUtil(TreeNode* root, int minVal, int maxVal)
    {
        if(root==NULL)
        return true;

        if(root->data<=minVal || root->data>=maxVal)
        return false;

        return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data,maxVal);



    }
		bool isBST(TreeNode* root){
			//your code goes here
            return isBSTUtil(root,INT_MIN,INT_MAX);
		}
};

//Time Complexity:O(n)
//SC=O(h)
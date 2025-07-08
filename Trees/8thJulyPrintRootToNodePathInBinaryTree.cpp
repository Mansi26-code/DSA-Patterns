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

    void solve(TreeNode* root, vector<int>&temp,vector<vector<int>>&res)
    {
        if(root==NULL)
        return;
        temp.push_back(root->data);
        if(root->left==NULL && root->right==NULL)
        {
            res.push_back(temp);
          
        }
       else{
            solve(root->left,temp,res);
            solve(root->right,temp,res);
       }
            temp.pop_back();
        
        
    }
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            //your code goes here
            vector<vector<int>>res;
            vector<int>temp;
            solve(root,temp,res);
            return res;

		}
};

//TC=O(N)
//SC=O(H)

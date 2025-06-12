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
    vector<int>inOrder(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL)
        return ans;

        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);

        return ans;
    }
		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here
            vector<int>ans;
            ans=inOrder(root,ans);
            vector<int>answer(2,-1);
            int index=-1;
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]==key)
                {
                    index=i;
                    break;
                }
            }
         
            answer[0]= (index-1>0)?ans[index-1]:-1;
            answer[1]=(index+1<ans.size())?ans[index+1]:-1;
            return answer;
		}
};
//TC & SC=O(n)
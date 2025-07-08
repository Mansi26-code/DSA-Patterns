class Solution {
public:
int maxPath=0;
void solve(TreeNode* root, bool goLeft,int steps)
{
    if(root==NULL)
    return;
    
    maxPath=max(maxPath,steps);
    if(goLeft)//mtlb left jaana h
    {
     solve(root->left,false,steps+1);//aage left nhi jaaenge
     solve(root->right,true,1);//glti se left chale gye, ab next right jaa skte hain and steps ko reset to 1

    }
    else
    {
        solve(root->right,true,steps+1);
        solve(root->left,false,1);
     
    }

}
    int longestZigZag(TreeNode* root) {
        solve(root,true,0);
        solve(root,false,0);
        return maxPath;
    }
};

// Time Complexity	O(N)
// Space Complexity	O(H) (H = height of tree)
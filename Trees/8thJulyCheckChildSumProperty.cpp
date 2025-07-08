/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
bool check(TreeNode* root)
{
    if(root==NULL)
    return true;

    if(root->left==NULL && root->right==NULL)
    return true;
    int left=root->left?root->left->val:0;
     int right=root->right?root->right->val:0;

     if(root->val!=left+right)
     return false;

     return check(root->left) && check(root->right);

}
    int checkChildrenSum(TreeNode* root) {
        // Your code goes here
        return check(root)?1:0;
    }
};


//TC=O(n)
//SC=O(h)

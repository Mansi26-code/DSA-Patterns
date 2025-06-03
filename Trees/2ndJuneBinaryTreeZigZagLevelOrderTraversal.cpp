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
class Solution{
public:
  vector<vector<int>>zigzagLevelOrder(TreeNode* root)
{
  
   queue<TreeNode*>q;
   vector<vector<int>>ans;

     if(root==NULL)
    return ans;
   q.push(root);
bool leftToRight=true;

   while(!q.empty())
{

 int  size=q.size();
vector<int>temp(size);
for(int i=0;i<size;i++)
{
  root=q.front();
  q.pop();
   
   int index=leftToRight?i:size-i-1;
   temp[index]=root->val;
if(root->left)
q.push(root->left);

if(root->right)
q.push(root->right);

 
}
leftToRight=!leftToRight;
ans.push_back(temp);


}
return ans;

  
}
};


/*
🔁 Time Complexity: O(n)
   - Every node is visited exactly once.

🧠 Space Complexity: O(n)
   - Due to queue (level order traversal) and result vector.
   - In the worst case (bottom-most level fully filled), the queue can store up to n/2 nodes.
*/

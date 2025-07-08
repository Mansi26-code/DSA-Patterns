class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        return 0;
        
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long maxWidth=0;
        while(!q.empty())
        {
            unsigned long long left=q.front().second;
            unsigned long long right=q.back().second;
            maxWidth=max(maxWidth,right-left+1);
            unsigned long long n=q.size();
            while(n--)
            {
                TreeNode* curr=q.front().first;
                unsigned long long idx=q.front().second;
                q.pop();

                if(curr->left)
                {
                    q.push({curr->left,2*idx+1});
                }
                if(curr->right)
                {
                    q.push({curr->right,2*idx+2});
                }
            }
        }
        return maxWidth;
    }
};


//Time Complexity:  O(N)
// Space Complexity: O(N)
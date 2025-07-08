/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();

            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }

            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }

        unordered_set<TreeNode*>visited;
        queue<pair<TreeNode*,int>>pq;
        pq.push({target,0});
        visited.insert(target);
        vector<int>ans;
        while(!pq.empty())
        {
            TreeNode* node=pq.front().first;
            int steps=pq.front().second;
            pq.pop();

            if(steps==k)
            {
                ans.push_back(node->val);
            }

            //left child
            if(node->left && !visited.count(node->left))
            {
                pq.push({node->left,steps+1});
                visited.insert(node->left);
            }

            //right child
            if(node->right && !visited.count(node->right))
            {
                pq.push({node->right,steps+1});
                visited.insert(node->right);
            }
            if(parent.count(node)&& !visited.count(parent[node]))
            {
                pq.push({parent[node],steps+1});
                visited.insert(parent[node]);
            }
        }
        return ans;
    }
};



// Time Complexity: O(N)

// Space Complexity: O(N)
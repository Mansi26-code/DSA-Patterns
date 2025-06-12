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
    vector<int> inOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return ans;

        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);

        return ans;
    }
    vector<int> kLargesSmall(TreeNode* root, int k) {
        // your code goes here
        // inorder traversal karo iska pehle
        vector<int> ans;

        ans = inOrder(root, ans);
        int n = ans.size();
        vector<int> answer(2, -1);
        answer[0] = ans[k - 1];
        answer[1] = ans[n - k];
        return answer;
    }
};

//TC & SC= O(n)
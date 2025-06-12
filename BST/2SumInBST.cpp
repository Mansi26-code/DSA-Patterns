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
    bool twoSumBST(TreeNode* root, int k) {
        // your code goes here
        vector<int> ans;
        ans = inOrder(root, ans);
        int i = 0, j = ans.size() - 1;
        while (i < j) {
            if (ans[i] + ans[j] == k) {
                return true;

            }

            else if (ans[i] + ans[j] > k)
                j--;

            else if (ans[i] + ans[j] < k)
                i++;
        }

        return false;
    }
};

//TC and SC=O(n)
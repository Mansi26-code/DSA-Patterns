/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    int floorBST(TreeNode* root, int key) {
        int floor = -1;
        while (root != NULL) {
            if (root->data == key) return root->data;

            if (root->data < key) {
                floor = root->data;
                root = root->right;
            } else
                root = root->left;
        }

        return floor;
    }

    int ceilBST(TreeNode* root, int key) {
        int ceil = -1;
        while (root != NULL) {
            if (root->data == key) return root->data;

            if (root->data > key) {
                ceil = root->data;
                root = root->left;
            } else
                root = root->right;
        }

        return ceil;
    }
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        // your code goes here

        vector<int> ans(2, 0);
        if (root == NULL) return ans;
        int floor = -1, ceil = -1;
        floor = floorBST(root, key);
        ceil = ceilBST(root, key);
        ans[0] = floor;
        ans[1] = ceil;
        return ans;
    }
};


Time Complexity:O(H)
Space Complexity:O(1)
// Implements an iterator over a BST that returns elements in sorted (inorder) order one by one.
// Supports next() and hasNext() in average O(1) time using O(h) space, where h is the tree height.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class BSTIterator {
   public:
    vector<int> inorder;
    int index;

    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->data);
        inorderTraversal(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        index = -1;
    }

    int next() {
        if (index + 1 < inorder.size()) {
            index++;
            return inorder[index];
        }
        return -1;
    }

    bool hasNext() { return index + 1 < inorder.size(); }
    bool hasPrev() { return index - 1 >= 0; }

    int prev() {
        if (index - 1 >= 0) {
            index--;
            return inorder[index];
        }
        return -1;
    }
};


//Time Complexity:The time complexity is O(n) for the constructor due to inorder traversal, and O(1) for next(), hasNext(), hasPrev(), and prev() operations.
//Space Complexity:The space complexity is O(n) because the inorder vector stores all node values.
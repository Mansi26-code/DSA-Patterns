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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: If root is null, simply return null
        if (root) {
            
            // If key is smaller than root's value, go left
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            }

            // If key is greater than root's value, go right
            else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            }

            // Node to be deleted is found
            else {
                // Case 1: Node has no children (it's a leaf)
                if (!root->left && !root->right) {
                    return NULL;  // Just delete the node
                }

                // Case 2: Node has only one child
                if (!root->left || !root->right) {
                    // Return the non-null child (left or right)
                    return root->left ? root->left : root->right;
                }

                // Case 3: Node has two children
                // We need to replace it with its inorder predecessor
                TreeNode* temp = root->left;

                // Find the rightmost node in the left subtree (inorder predecessor)
                while (temp->right) {
                    temp = temp->right;
                }

                // Replace the value of current node with predecessor's value
                root->val = temp->val;

                // Delete the predecessor node from the left subtree
                root->left = deleteNode(root->left, temp->val);
            }
        }

        // Return the modified root
        return root;
    }
};


Time Complexity: The time complexity is O(h) where h is the height of the tree. In the worst-case scenario (skewed tree), h can be n, making it O(n). In the best-case (balanced tree), h would be log(n), making it O(log n).
Space Complexity: The space complexity is O(h) due to the recursive calls, where h is the height of the tree. In the worst case, this becomes O(n), and in the best case (balanced tree), it's O(log n).
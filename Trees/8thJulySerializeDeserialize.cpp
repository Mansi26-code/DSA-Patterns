/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL)
            {
                s.append("#,");
            }
            else
            {
                s.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#")
            {
                node->left=NULL;
            }
            else
            {
                TreeNode* leftVal=new TreeNode(stoi(str));
                node->left=leftVal;
                q.push(leftVal);
            }


            getline(s,str,',');
            if(str=="#")
            {
                node->right=NULL;
            }
            else
            {
                TreeNode* rightVal=new TreeNode(stoi(str));
                node->right=rightVal;
                q.push(rightVal);
            }
        }
        return root;
    }
};

//TC & SC= O(N)9
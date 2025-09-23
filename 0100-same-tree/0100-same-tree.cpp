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
    void Inorder(TreeNode* root  , vector<int>& v)
    {
        if(root!=NULL) 
        {
        Inorder(root->left , v);
        v.push_back(root->val);
        Inorder(root->right , v);
        }
        else
        {
            v.push_back(100000);
        }
    }
    void preorder(TreeNode* root  , vector<int>& v)
    {
        if(root!=NULL) 
        {
        v.push_back(root->val);
        preorder(root->left , v);
        preorder(root->right , v);
        }
        else
        {
            v.push_back(100000);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> inp , inq ,prp , prq;

        Inorder(p , inp);
        Inorder(q , inq);
        preorder(p , prp);
        preorder(q , prq);

        if(inp==inq && prp==prq  )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
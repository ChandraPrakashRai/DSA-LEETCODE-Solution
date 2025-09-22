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
    int height(TreeNode* root , int &valid)
    {
        if(root==NULL) return 0;

        int lh = height(root->left , valid);

        int rh = height(root->right , valid);

        if(abs(lh-rh) > 1) 
        {
            valid = 0;
            return valid;
        }

        return 1+max(lh , rh);
    }
    bool isBalanced(TreeNode* root) {
        int valid = 1;
        height(root , valid);

        return valid;
    }
};
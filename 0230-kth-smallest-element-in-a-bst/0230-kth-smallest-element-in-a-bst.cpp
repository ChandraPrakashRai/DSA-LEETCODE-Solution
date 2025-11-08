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
       void inorder(TreeNode* root ,  vector<int>&ans)
        {
            if(!root)
            return;
            // left 
            inorder(root->left , ans);

            //node
            ans.push_back(root->val);

            //right
            inorder(root->right , ans);
        }
    int kthSmallest(TreeNode* root, int k ) {
        
        vector<int>ans;
        inorder(root, ans);
        
       return ans[k-1];

    }
};
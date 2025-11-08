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
    void inorder(TreeNode* root , vector<int>&ans)
    {
        if(root==NULL)
        return;

        // left
        inorder(root->left , ans);

        // node
        ans.push_back(root->val);

        //right
        inorder(root->right , ans);
    }
    bool isValidBST(TreeNode* root) {

        vector<int>ans;

        inorder(root , ans);

        for(int  i = 1 ; i<ans.size() ; i++)
            if(ans[i] <= ans[i-1])
            return 0;
        

        return 1;

        
    }
};
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
    int dfs(TreeNode* root , int &count)
    {
        if(!root) return 0;

        int left = dfs(root->left , count);
        int right = dfs(root->right , count);

        count = count + abs(left) + abs(right);

        return root->val-1 + left + right;


    }
    int distributeCoins(TreeNode* root) {
        int count = 0;
        dfs(root , count);
        return count;

    }
};
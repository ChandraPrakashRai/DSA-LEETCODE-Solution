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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<vector<int>>ans;

        que.push(root);

        if(root==NULL) return { };

        while(!que.empty())
        {
            int n = que.size();
            vector<int>result;
            for(int i =0 ; i<n ; i++)
            {
                TreeNode* temp = que.front();
                que.pop();

                result.push_back(temp->val);

            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);   
            }
            ans.push_back(result);
            


        }

        return ans;
    }
};
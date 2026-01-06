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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>que;
        int res=INT_MIN;
        int res_levl = 0;
        que.push(root);
        int curr_lev = 1;

        while(!que.empty())
        {
            int n = que.size();

            int sum = 0;
            while(n--)
            {
                TreeNode*  temp = que.front();
                que.pop();

                if(temp->left)
                {
                    que.push(temp->left);
                }
                if(temp->right)
                {
                    que.push(temp->right);
                }

                sum = sum + temp->val;

                
            }
            if(sum>res){
            res = sum;
            res_levl = curr_lev;
            }

            curr_lev++;
            
        }
        return res_levl;
    }
};
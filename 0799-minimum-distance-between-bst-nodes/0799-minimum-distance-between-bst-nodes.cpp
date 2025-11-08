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
void inorder(TreeNode* root, vector<int>&ans)
{
    
    if(!root)
    return;

    //left
    inorder(root->left , ans);
    

    //node 
    ans.push_back(root->val);

    //right
    inorder(root->right , ans);
}
    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        inorder(root , ans);
        vector<int>result;
        


        for(int i = 0 ; i<ans.size()-1; i++)

        {
            
                 result.push_back(abs(ans[i]-ans[i+1]));
            
        }

       int res = result[0];
        for(int i = 1 ; i<result.size() ; i++)
        {
           
            res = min(res , result[i]);
            
        }
        
        return res;
    }
};
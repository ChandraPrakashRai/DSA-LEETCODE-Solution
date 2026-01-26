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

vector<vector<int>>zigzag(TreeNode* root)
{
     vector<vector<int>>ans;
    if(!root)
    return ans;
    
    queue<TreeNode*>que;
   
    
    que.push(root);

    bool leftToright = true;
    
    while(!que.empty())
    {
        int n = que.size();
        vector<int>curr(n);
        for(int i = 0 ; i<n ; i++)
        {
            
             TreeNode* temp = que.front();
             que.pop();
            

            int index = (leftToright) ? i : n-1-i;
             
            curr[index] = temp->val;
            if(temp->left) que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
        
        ans.push_back(curr);
        leftToright = !leftToright;
    }
    
    return ans;
    
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       return  zigzag(root);
    }
};
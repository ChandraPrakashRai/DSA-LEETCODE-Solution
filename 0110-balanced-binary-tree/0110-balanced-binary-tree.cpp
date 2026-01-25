
class Solution {
public:
int a = 1;
int height(TreeNode* root)
{
    if(!root) return 0;

    int left = height(root->left);
    int right =  height(root->right);

    if(abs(left-right)>1)
    a = 0;

    return 1+max(left , right);
}
    bool isBalanced(TreeNode* root) {
        height(root);

        return a;
    }
};
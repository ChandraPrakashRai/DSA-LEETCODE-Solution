class Solution {
public:

vector<vector<int>>perm(vector<int>nums , int idx , vector<vector<int>>&ans , int n)
{
    if(idx==n)
    {
        ans.push_back(nums);
    
    }

    //recusrsive code
    for(int i = idx ; i<n ; i++)
    {
        swap(nums[i] , nums[idx]);
        perm(nums , idx+1 , ans , n);

        //backtrack
        swap(nums[i] , nums[idx]);
    }

    return ans;
}
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int n = nums.size();

       return  perm(nums , 0 , ans , n);
    }
};
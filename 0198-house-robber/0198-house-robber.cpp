class Solution {
public:
    int find(vector<int>&nums , int index , int n , vector<int>&dp)

    {
        if(index>=n)
        return 0;

        if(dp[index]!=-1)
        return dp[index];

        return dp[index] =   max(nums[index] + find(nums , index+2 , n , dp) , find(nums , index+1 , n , dp));

    }
    int rob(vector<int>& nums) {
            int index =  0 ;
            int n = nums.size();
             vector<int>dp(n+2 , -1);

        return find(nums , 0 , n , dp);
    }
};
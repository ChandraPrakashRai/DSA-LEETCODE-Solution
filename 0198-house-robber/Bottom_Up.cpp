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
           
            int n = nums.size();
             vector<int>dp(n+2);

             dp[n] = dp[n+1] = 0;

             for(int i = n-1 ; i>=0 ; i--)
             {
                dp[i] =  max(nums[i] + dp[i+2] , dp[i+1]);
             }

             return dp[0];

    }
};

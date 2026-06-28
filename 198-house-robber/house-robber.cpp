class Solution {
public:

    int maximum(vector<int>& nums , int index , vector<int>&dp)
    {
       
         if(index==0) return nums[index];
         if(index==1) return max(nums[0] , nums[1]);

        if(dp[index]!=-1)
        return dp[index];

         int pick = nums[index] + maximum(nums , index - 2 ,dp);
         int notpick = 0 + maximum(nums , index - 1 ,dp);

         return dp[index] = max(pick , notpick);


     }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1 , -1);
        return maximum(nums ,  nums.size()-1 , dp);
    }
};
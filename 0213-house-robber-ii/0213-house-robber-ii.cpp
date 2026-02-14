class Solution {
public:
     int  cost(vector<int>&nums , int index , vector<int>&dp)
     {
        // base case
        if(index==0)
        return nums[0];

        if(index<1) return 0;

        if(dp[index]!=-1) return dp[index];

        int pick = nums[index] + cost(nums , index-2  , dp);

        int notpick = 0 + cost(nums , index-1 , dp);

        return  dp[index] =  max(pick , notpick);
     }
    int rob(vector<int>& nums) {
       if(nums.size()==1)
       return nums[0];
        
        //first case
        vector<int>nums1(nums.begin() , nums.end()-1);
        vector<int>dp1(nums1.size() ,-1);
        //second case
        vector<int>nums2(nums.begin()+1 , nums.end());
        vector<int>dp2(nums2.size(),-1);

        int first = cost(nums1 , nums1.size()-1 , dp1);
        int second = cost(nums2 , nums2.size()-1, dp2);

        return max(first , second);
        
    }
};
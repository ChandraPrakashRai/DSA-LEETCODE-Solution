class Solution {
public:
    int LIS(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
        if (curr == nums.size()) return 0;

        if (dp[prev+1][curr] != -1)
            return dp[prev+1][curr];

        int take = 0;
        if (prev == -1 || nums[prev] < nums[curr])
            take = 1 + LIS(curr, curr+1, nums, dp);

        int nottake = LIS(prev, curr+1, nums, dp);

        return dp[prev+1][curr] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return LIS(-1, 0, nums, dp);
    }
};

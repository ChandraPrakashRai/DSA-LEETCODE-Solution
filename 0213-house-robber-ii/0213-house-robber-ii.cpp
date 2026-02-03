class Solution {
public:
    int maxAmount(vector<int>& nums, int index, vector<int>& dp) {
        if (index < 0) return 0;
        if (index == 0) return nums[0];

        if (dp[index] != -1)
            return dp[index];

        int take = nums[index] + maxAmount(nums, index - 2, dp);
        int skip = maxAmount(nums, index - 1, dp);

        return dp[index] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // case 1: houses 0 to n-2
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> dp1(nums1.size(), -1);
        int first_case = maxAmount(nums1, nums1.size() - 1, dp1);

        // case 2: houses 1 to n-1
        vector<int> nums2(nums.begin() + 1, nums.end());
        vector<int> dp2(nums2.size(), -1);
        int second_case = maxAmount(nums2, nums2.size() - 1, dp2);

        return max(first_case, second_case);
    }
};

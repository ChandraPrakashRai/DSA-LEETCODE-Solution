class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0;
        int maxWindow = 0;

        for (int j = 0; j < n; j++) {
            while (nums[j] > (long long)k * nums[i]) {
                i++;   // shrink window from left
            }
            maxWindow = max(maxWindow, j - i + 1);
        }

        return n - maxWindow;
    }
};

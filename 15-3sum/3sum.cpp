class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Traverse the array
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate elements for the first pointer
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // The remaining sum we need to find
            int start = i + 1, end = n - 1;

            // Step 3: Use two-pointer approach
            while (start < end) {
                int sum = nums[start] + nums[end];

                if (sum == target) {
                    result.push_back({nums[i], nums[start], nums[end]});

                    // Skip duplicates for the second and third pointers
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;

                    // Move both pointers
                    start++;
                    end--;
                } else if (sum < target) {
                    start++; // Increase sum
                } else {
                    end--; // Decrease sum
                }
            }
        }

        return result;
    }
};
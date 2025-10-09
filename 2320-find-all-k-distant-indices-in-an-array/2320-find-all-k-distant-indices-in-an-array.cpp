class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);

                // Avoid duplicate indices (if previous range overlaps)
                if (!ans.empty() && ans.back() >= start) {
                    start = ans.back() + 1;
                }

                for (int j = start; j <= end; j++) {
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};

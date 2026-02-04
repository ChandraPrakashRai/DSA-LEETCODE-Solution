class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        vector<vector<int>> L(n + 1), R(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }
            L[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }
            R[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(R[i].begin(), R[i].end());
        }

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {
            for (int x : L[k]) {
                int need = totalSum / 2 - x;
                auto &vec = R[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), need);

                if (it != vec.end())
                    ans = min(ans, abs(totalSum - 2 * (x + *it)));
                if (it != vec.begin()) {
                    --it;
                    ans = min(ans, abs(totalSum - 2 * (x + *it)));
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         long long absSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                absSum += abs(val);
                if (val < 0) negCount++;
                minAbs = min(minAbs, abs(val));
            }
        }

        if (negCount % 2 == 0) {
            return absSum;
        } else {
            return absSum - 2LL * minAbs;
        }

    }
};
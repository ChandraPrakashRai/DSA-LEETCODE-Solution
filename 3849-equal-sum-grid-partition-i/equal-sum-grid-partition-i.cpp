class Solution {
public:

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1)
            return false;

        long long total = 0;

        // Step 1: total sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }

        // Step 2: must be even
        if(total % 2 != 0)
            return false;

        long long target = total / 2;

        // Step 3: Horizontal cuts
        long long rowSum = 0;

        for(int i = 0; i < n - 1; i++) {

            for(int j = 0; j < m; j++) {
                rowSum += grid[i][j];
            }

            if(rowSum == target)
                return true;
        }

        // Step 4: Vertical cuts
        long long colSum = 0;

        for(int j = 0; j < m - 1; j++) {

            for(int i = 0; i < n; i++) {
                colSum += grid[i][j];
            }

            if(colSum == target)
                return true;
        }

        return false;
    }
};
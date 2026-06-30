class Solution {
public:
    int path2(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp) {
        // Out of bounds
        if (i < 0 || j < 0) return 0;

        // Obstacle cell
        if (obstacleGrid[i][j] == 1) return 0;

        // Base case: starting cell
        if (i == 0 && j == 0) return 1;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        int up = path2(obstacleGrid, i - 1, j, dp);
        int left = path2(obstacleGrid, i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return path2(obstacleGrid, m - 1, n - 1, dp);
    }
};

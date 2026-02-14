class Solution {
public:

int minSum(vector<vector<int>>&grid , int i , int j , vector<vector<int>>&dp)
{
    // base case
    if(i==0 && j==0)
    return dp[i][j] = grid[i][j];
    
     if (i < 0 || j < 0)
        return 1e9;
    

    if(dp[i][j]!=-1)
    return dp[i][j];
    //recursive case

     
     int up = grid[i][j] +  minSum(grid , i-1 , j , dp);
     int left = grid[i][j]  + minSum(grid , i , j-1 , dp);
     
     return dp[i][j] = min(up , left);
    
}
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m, -1));
        return minSum(grid , n-1 , m-1 , dp);
    }
};
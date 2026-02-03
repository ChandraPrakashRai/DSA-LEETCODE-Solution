class Solution {
public:

    int count(int m , int n , vector<vector<int>>& grid , int i , int j  , vector<vector<int>>& dp){
        if(i==m-1 && j==n-1)
        return grid[i][j];

        if(dp[i][j]!=-1)
        return dp[i][j] ;

        if(i==m-1)
        {
         return   grid[i][j] + count(m , n , grid , i , j+1 , dp);
        }

        if(j==n-1)
        {
          return  grid[i][j] + count(m , n , grid , i+1 , j , dp);
        }
        
        int down = count(m , n , grid , i+1 , j , dp);

        int right = count(m , n , grid , i , j+1, dp);

        return  dp[i][j] = grid[i][j] + min(down , right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m , vector<int>(n , -1));

        return count(m , n,grid , 0 , 0 , dp);
    }
};
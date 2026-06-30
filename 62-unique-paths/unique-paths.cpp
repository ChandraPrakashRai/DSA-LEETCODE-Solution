class Solution {
public:
    int path(int m , int n , int i , int j , vector<vector<int>>&dp)
    {
        // base case
        if(i<0 || j<0) return 0;

        if(i==0 && j==0)
        {
            return 1;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];




        int up = path(m , n , i-1 , j , dp) ;
        int left = path(m , n , i , j-1 , dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        return path(m , n , m-1 , n-1 , dp);
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {

        // ak mai dp bna lunga 2D DP 
        // last row and last column ko
        // 1 se initialize krn ahai islize 
        // poore 2D DP ko inityially 1 se initialize kr rha hu 

        vector<vector<int>>dp(m , vector<int>(n,1));

        for(int i = m-2 ; i>=0 ; i--)
        for(int j = n-2 ; j>=0 ; j--)

         dp[i][j]=dp[i+1][j]+dp[i][j+1];

         return dp[0][0];
        
    }
};
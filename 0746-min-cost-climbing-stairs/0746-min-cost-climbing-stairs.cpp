class Solution {
public:
    int minCost(int n , vector<int>& cost , vector<int>&dp )
    {
        if(n==1 || n==0)
        return 0;

        if(dp[n]!=-1)
        return dp[n];

       return dp[n] = min(minCost(n-1 , cost , dp) + cost[n-1], minCost(n-2 , cost , dp) + cost[n-2]);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1 , -1);
        return minCost(n , cost, dp);

    }
};
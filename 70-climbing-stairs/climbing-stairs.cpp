class Solution {
public:

int stairs(int n , vector<int>&dp)
{
    if(n==0) return 1;

    if(n==1) return 1;

    int prev1 = 1;
    int prev2 = 1;

    for(int i =2 ; i<=n ; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
    int climbStairs(int n) {
        
        // dp
        vector<int>dp(n+1);

        return stairs(n , dp);
    }
};
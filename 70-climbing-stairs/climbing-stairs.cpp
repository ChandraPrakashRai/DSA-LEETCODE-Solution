class Solution {
public:
int steps(int n  , int index , vector<int>&dp)
{
     if(index==n)
    {
        return dp[index] = 1;
    }
    
    if(index>n)
    {
        return  0;
    }
    
    if(dp[index]!=-1)
    return dp[index];
    
    int one_step = steps(n , index+1 , dp);
    int two_step = steps(n , index+2 , dp);
    
    
    return dp[index] = one_step+two_step;
    
    
}

    int climbStairs(int n) {
 vector<int>dp(n+1 , -1);
    if(n==0 || n==1)
    {
        cout<<1;
    }
    
    
    return steps(n , 0 , dp);
        
    }
};
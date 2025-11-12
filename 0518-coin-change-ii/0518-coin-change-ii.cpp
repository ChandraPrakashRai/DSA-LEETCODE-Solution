class Solution {
public:
int find(int index , vector<int>&coins , int amount  , int n , vector<vector<int>>& dp)
{
    if(amount==0)
    return 1;

    if(amount<0 || index>=n)
    return 0;

    if(dp[index][amount]!=-1)
    return dp[index][amount];


    // coin le liya
    int take = find(index , coins , amount-coins[index] , n , dp);
    //coin nhi liya hmne
    int nottake = find(index+1 , coins , amount , n , dp);

    return  dp[index][amount] =  take + nottake ;
}
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , -1));


        return find(0 , coins , amount , n , dp);
        
    }
};
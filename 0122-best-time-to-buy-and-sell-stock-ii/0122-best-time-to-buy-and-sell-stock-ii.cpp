class Solution {
public:
    vector<vector<int>> dp;

    int profit(vector<int>& prices, int index, int canBuy)
    {
        // base case
        if(index == prices.size())
            return 0;

        if(dp[index][canBuy] != -1)
            return dp[index][canBuy];

        int ans;
        if(canBuy)
        {
            ans = max(
                -prices[index] + profit(prices, index+1, 0), // BUY
                 profit(prices, index+1, 1)                  // SKIP
            );
        }
        else
        {
            ans = max(
                 prices[index] + profit(prices, index+1, 1), // SELL
                 profit(prices, index+1, 0)                  // HOLD
            );
        }

        return dp[index][canBuy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return profit(prices, 0, 1);
    }
};

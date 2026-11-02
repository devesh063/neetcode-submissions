class Solution {
public:
    int minCoin(vector<int> &coins, int n, int amount, vector<vector<int>> &dp)
    {
        if(amount == 0)
          return 0;
          
        if(n == 0)
          return (int)1e9;
        
        if(dp[n][amount] != -1)
          return dp[n][amount];

        int notPick = minCoin(coins,n-1,amount,dp);
        int pick = (int)1e9;

        if(amount >= coins[n-1])
           pick = 1 + minCoin(coins,n,amount-coins[n-1],dp);

        return dp[n][amount] = min(notPick,pick);  
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = minCoin(coins,n,amount,dp);

        return ans == (int)1e9 ? -1 : ans;    
    }
};

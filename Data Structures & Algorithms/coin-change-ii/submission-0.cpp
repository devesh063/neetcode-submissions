class Solution {
public:
    int findWays(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp)
    {
        if(amount == 0)
          return 1;

        if(idx < 0)  return 0;
        
        if(dp[idx][amount] != -1)
          return dp[idx][amount];

        int ways = 0;

        ways = findWays(coins,amount,idx-1, dp);
        
        if(amount >= coins[idx])
        {
            ways += findWays(coins,amount - coins[idx], idx, dp);
        }
        return dp[idx][amount] = ways;
    }
    int change(int amount, vector<int>& coins) 
    {
       int n = coins.size();
       vector<vector<int>> dp(n, vector<int>(amount+1, -1));

       return findWays(coins,amount,n-1,dp);    
    }
};

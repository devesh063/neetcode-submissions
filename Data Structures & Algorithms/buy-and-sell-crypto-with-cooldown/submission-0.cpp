class Solution {
public:
    int maxProfitCanEarn(vector<int> prices, bool isBuy, int idx, int n, vector<vector<int>> &dp)
    {
        if(idx >= n)
          return 0;
        
        if(dp[idx][isBuy] != -1)
          return dp[idx][isBuy];

        if(isBuy)
         return dp[idx][isBuy] = max(-prices[idx] + maxProfitCanEarn(prices,false,idx+1,n,dp), maxProfitCanEarn(prices,true,idx+1,n,dp));
        else
          return dp[idx][isBuy] = max(prices[idx] + maxProfitCanEarn(prices,true,idx+2,n,dp) , maxProfitCanEarn(prices,false,idx+1,n,dp));
    }
    int maxProfit(vector<int>& prices) 
    {
       int n = prices.size();
       
       vector<vector<int>> dp(n, vector<int>(2,-1));

       return maxProfitCanEarn(prices,true,0,n,dp);    
    }
};

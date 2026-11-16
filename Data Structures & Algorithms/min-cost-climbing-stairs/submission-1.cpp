class Solution {
public:
    int minCost(vector<int> &cost, int idx, int n, vector<int> &dp)
    {
        if(idx >= n)
          return 0;
        
        if(dp[idx] != -1)
          return dp[idx];

        return  dp[idx] = cost[idx] + min(minCost(cost, idx + 1, n, dp), minCost(cost, idx+2, n, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
       int n = cost.size();

       vector<int> dp1(n,-1);
       vector<int> dp2(n,-1);
       return min(minCost(cost,0,n,dp1), minCost(cost,1,n,dp2));    
    }
};

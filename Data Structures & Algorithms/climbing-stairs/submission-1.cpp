class Solution {
public:
    int findWays(int idx, int n, vector<int> &dp)
    {
        if(idx == n)  return 1;
        
        if(dp[idx] != -1)
          return dp[idx];

        int ways = 0;

        ways = findWays(idx+1,n,dp);

        if(idx + 2 <= n)
          ways += findWays(idx+2,n,dp);

        return dp[idx] =  ways;
    }
    int climbStairs(int n) 
    {
       vector<int> dp(n,-1);

       return findWays(0,n,dp);    
    }
};

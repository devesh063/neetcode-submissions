class Solution {
public:
    int findWays(string &s, string &t, int n, int m, vector<vector<int>> &dp)
    {
        if(m == 0)
          return 1;
        if(n == 0)
          return 0;
        
        if(dp[n][m] != -1)
          return dp[n][m];

        int ways = 0;

        if(s[n-1] == t[m-1])
          ways = findWays(s,t,n-1,m-1,dp) + findWays(s,t,n-1,m,dp);
        else
          ways += findWays(s,t,n-1,m,dp);
        return dp[n][m] = ways;  
    }
    int numDistinct(string s, string t) 
    {
       int n = s.size(), m = t.size();

       vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
       return findWays(s,t,n,m,dp);    
    }
};

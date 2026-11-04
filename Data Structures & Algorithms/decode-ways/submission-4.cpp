class Solution {
public:
    int findWays(string &s, int idx, int n, vector<int> &dp)
    {
        if(idx == n)
          return 1;

        int ways = 0;

        if(dp[idx] != -1)
          return dp[idx];

        if(s[idx] != '0')
        {
           ways = findWays(s,idx+1,n,dp);
        }

        if(idx + 1 < n)
        {
            if((s[idx] == '1' && s[idx+1] <= '9') || (s[idx] == '2' && s[idx+1] <= '6'))
              ways += findWays(s,idx+2,n,dp);
        }
        return dp[idx] = ways;
    }
    int numDecodings(string s) 
    {
       int n = s.size();
       vector<int> dp(n,-1);

       return findWays(s,0,n,dp);    
    }
};

class Solution {
public:
    bool isMatch(string &s1, string &s2, string &s3, int n, int m, vector<vector<int>> &dp)
    {
        int k = m + n;

        if(n == 0 && m == 0)
          return true;
        
        if(dp[n][m] != -1)
          return dp[n][m];

        bool res = false;

        if(n > 0 && m > 0 && k > 0 && s1[n-1] == s3[k-1] && s2[m-1] == s3[k-1])
        {
            res = (isMatch(s1,s2,s3,n-1,m,dp) || isMatch(s1,s2,s3,n,m-1,dp));
        }
        else if(n > 0 && k > 0 && s1[n-1] == s3[k-1])
        {
            res = isMatch(s1,s2,s3,n-1,m,dp);
        }
        else if(m > 0 && k > 0 && s2[m-1] == s3[k-1])
        {
            res = isMatch(s1,s2,s3,n,m-1,dp);
        }
        return dp[n][m] = res;
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
       int n = s1.size(), m = s2.size();
       
       if(n+m != s3.size())
         return false;
       vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

       return isMatch(s1,s2,s3,n,m,dp);    
    }
};

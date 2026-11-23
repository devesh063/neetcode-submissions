class Solution {
public:
    bool match(string &s, string &p, int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if(j == m)
          return i == n;

        if(dp[i][j] != -1)
          return dp[i][j];

        bool matched = (i < n && (s[i] == p[j] || p[j] == '.'));

        if(j+1 < m && p[j+1] == '*')
        {
            return dp[i][j] = match(s,p,i,j+2,n,m,dp) || (matched && match(s,p,i+1,j,n,m,dp));
        }

        return dp[i][j] = matched && match(s,p,i+1,j+1,n,m,dp);
    }
    bool isMatch(string s, string p) 
    {
       int n = s.size(), m = p.size();
       
       vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

       return match(s,p,0,0,n,m,dp);    
    }
};

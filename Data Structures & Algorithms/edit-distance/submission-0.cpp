class Solution {
public:
    int minOp(string &word1, string &word2, int n, int m, vector<vector<int>> &dp)
    {
        if(m == 0)
          return n;
        if(n == 0)
          return m;
        
        if(dp[n][m] != -1)
          return dp[n][m];

        int op1 = (int)1e9, op2 = (int)1e9;

        if(word1[n-1] == word2[m-1])
        {
            op1 = minOp(word1,word2,n-1,m-1,dp);    
        }
        else
        {
            op2 = 1 + min(minOp(word1,word2,n-1,m,dp),min(minOp(word1,word2,n-1,m-1,dp),minOp(word1,word2,n,m-1,dp)));
        }
        return dp[n][m] = min(op1,op2);
    }
    int minDistance(string word1, string word2) 
    {
       int n = word1.size(), m = word2.size();

       vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
       return minOp(word1,word2,n,m,dp);    
    }
};

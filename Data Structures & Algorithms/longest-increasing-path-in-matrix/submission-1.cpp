class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int rw, int cl, int n, int m)
    {
        if(dp[rw][cl] != -1)
          return dp[rw][cl];

        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};
        
        int len = 1;

        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m) && matrix[newRw][newCl] > matrix[rw][cl])
            {
                len = max(len,1 + dfs(matrix,dp,newRw,newCl,n,m));
            }
        }
        return dp[rw][cl] = len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxLen = max(maxLen,dfs(matrix,dp,i,j,n,m));
            }
        }
        return maxLen;    
    }
};

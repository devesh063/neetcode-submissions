class Solution {
public:
    bool isValid(int rw, int cl)
    {
        if(rw >= 0 && cl >= 0)
          return true;
        return false;
    }
    int findUqPaths(int rw, int cl, vector<int> &dirRw, vector<int> &dirCl, vector<vector<int>> &dp)
    {
        if(rw == 0 && cl == 0)
          return 1;
        
        if(dp[rw][cl] != -1)
          return dp[rw][cl];

        int paths = 0;

        for(int i=0; i<2; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl))
            {
                paths += findUqPaths(newRw,newCl,dirRw,dirCl,dp);
            }
        }
        return dp[rw][cl] = paths;
    }
    int uniquePaths(int m, int n) 
    {
       vector<int> dirRw = {-1,0}, dirCl = {0,-1};
       vector<vector<int>> dp(m,vector<int>(n,-1));

       return findUqPaths(m-1,n-1,dirRw,dirCl,dp);   
    }
};

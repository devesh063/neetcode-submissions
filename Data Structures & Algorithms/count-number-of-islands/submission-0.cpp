class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    void dfs(auto &grid, int rw, int cl, int n, int m, auto &visited, auto &dirRw, auto &dirCl)
    {
        visited[rw][cl] = true;


        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m) && !visited[newRw][newCl]  && grid[newRw][newCl] == '1')
            {
                dfs(grid,newRw,newCl,n,m,visited,dirRw,dirCl);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};

        int cnt = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    ++cnt;
                    dfs(grid,i,j,n,m,visited,dirRw,dirCl);
                }
            }
        }
        return cnt;    
    }
};

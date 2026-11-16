class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    int dfs(vector<vector<int>> &grid, int rw, int cl, vector<vector<bool>> &visited)
    {
        visited[rw][cl] = true;

        int area = 1;

        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};

        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,grid.size(),grid[0].size()) && !visited[newRw][newCl]  && grid[newRw][newCl] == 1)
            {
                //area = max(area, 1+dfs(grid,newRw,newCl,visited));

                area += dfs(grid,newRw,newCl,visited);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
       int n = grid.size(), m = grid[0].size();
       vector<vector<bool>> visited(n, vector<bool>(m,false));
       int maxArea = 0;

       for(int i=0; i<n; i++)
       {
         for(int j=0; j<m; j++)
         {
            if(!visited[i][j] && grid[i][j] == 1)
            {
                maxArea = max(maxArea,dfs(grid,i,j,visited));
            }
         }
       }
       return maxArea;    
    }
};

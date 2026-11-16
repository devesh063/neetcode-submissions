class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
       queue<pair<int,pair<int,int>>> q;
       int n = grid.size(), m = grid[0].size();
       vector<vector<bool>> visited(n, vector<bool>(m,false));

       for(int i=0; i<n; i++)
       {
         for(int j=0; j<m; j++)
         {
            if(grid[i][j] == 0)
            {
                q.push({0,{i,j}});
                //visited[i][j] = true;
            }
         }
       }

       vector<int> dirRw = {1,0,0,-1};
       vector<int> dirCl = {0,1,-1,0};

       while(!q.empty())
       {
          auto it = q.front(); q.pop();

          int dist = it.first, rw = it.second.first, cl = it.second.second;

          for(int i=0; i<4; i++)
          {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m) && !visited[newRw][newCl] && grid[newRw][newCl] == INT_MAX)
            {
                grid[newRw][newCl] = 1 + dist;
               // visited[newRw][newCl] = true;
                q.push({grid[newRw][newCl],{newRw,newCl}});
            }
          }
       } 

    }
};

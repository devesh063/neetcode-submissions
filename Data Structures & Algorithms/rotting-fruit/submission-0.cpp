class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;

        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl  = {0,1,-1,0};
        int totalTime = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                  q.push({0,{i,j}});         
            }
        }

        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            
            int time = it.first,  rw = it.second.first, cl = it.second.second;
            
            totalTime = max(totalTime,time);

            for(int i=0; i<4; i++)
            {
                int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

                if(isValid(newRw,newCl,n,m) && grid[newRw][newCl] == 1)
                {
                    grid[newRw][newCl] = 2; //mark as rotten
                    q.push({time+1,{newRw,newCl}});
                }
            } 
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
              if(grid[i][j] == 1)
                return -1;
        }
        return totalTime;
    }
};

class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return  false;
    }
    void dfs(auto &heights, auto &visited, auto &dirRw, auto &dirCl, int rw, int cl, int n, int m)
    {
        visited[rw][cl] = true;

        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m) && !visited[newRw][newCl]  && heights[newRw][newCl] >= heights[rw][cl])
            {
                dfs(heights,visited,dirRw,dirCl,newRw,newCl,n,m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> pacific(n, vector<bool>(m,false));
        vector<vector<bool>> atlantic(n, vector<bool>(m,false));
        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};

        //start from top row (from pacific)
        for(int i=0; i<m; i++)
        {
            dfs(heights,pacific,dirRw,dirCl,0,i,n,m);
        }

        //start from first column (from pacific)
        for(int i=0; i<n; i++)
        {
            dfs(heights,pacific,dirRw,dirCl,i,0,n,m);
        }
        
        //bottom row
        for(int i=0; i<m; i++)
        {
            dfs(heights,atlantic,dirRw,dirCl,n-1,i,n,m);
        }

        //last column 
        for(int i=0; i<n; i++)
        {
            dfs(heights,atlantic,dirRw,dirCl,i,m-1,n,m);
        }


        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                  ans.push_back({i,j});
            }
        }
        return ans;
    }
};

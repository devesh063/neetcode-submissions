class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int,int>> q; 
        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};

        for(int i=0; i<m; i++)
        {
            if(board[0][i] == 'O')
            {
                q.push({0,i});
                visited[0][i] = true;
            }

            if(board[n-1][i] == 'O') 
            {
                q.push({n-1,i});
                visited[n-1][i] = true;
            }
        }    

        for(int i=0; i<n; i++)
        {
            if(board[i][0] == 'O')
            {
               q.push({i,0});
               visited[i][0] = true;
            } 
            if(board[i][m-1] == 'O') 
            {
                q.push({i,m-1});
                visited[i][m-1] = true;
            }
        }

        while(!q.empty())
        {
            auto it = q.front(); q.pop();

            int rw = it.first, cl = it.second;
            
            for(int i=0; i< 4; i++)
            {
                int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

                if(isValid(newRw,newCl,n,m) && !visited[newRw][newCl] && board[newRw][newCl] == 'O')
                {
                    visited[newRw][newCl] = true;
                    q.push({newRw,newCl});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j])
                  board[i][j] = 'X';
            }
        }
    }
};

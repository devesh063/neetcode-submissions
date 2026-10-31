class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    bool dfs(vector<vector<char>> &board, int rw, int cl, int matchIdx, string &word, vector<vector<bool>> &visited , vector<int> &dirRw, vector<int> &dirCl, int n, int m)
    {

        if(matchIdx == word.size())
          return true;
          
        visited[rw][cl] = true;

        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m) && !visited[newRw][newCl] && board[newRw][newCl] ==  word[matchIdx])
            {
                if(dfs(board,newRw,newCl,matchIdx+1,word,visited,dirRw,dirCl,n,m))
                  return true;
            }
        }

        visited[rw][cl] = false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
       int n = board.size(), m = board[0].size();
       
       vector<vector<bool>> visited(n, vector<bool>(m,false));
       vector<int> dirRw = {1,0,0,-1};
       vector<int> dirCl = {0,1,-1,0};

       for(int i=0; i<n; i++)
       {
        for(int j=0; j<m; j++)
        {
            if(board[i][j] == word[0])
            {
                cout << "i :" << i << "j :" << j << " " <<board[i][j] << "\n";
                if(dfs(board,i,j,1,word,visited,dirRw,dirCl,n,m))
                  return true;
            }
        }
       }    
       return false;
    }
};

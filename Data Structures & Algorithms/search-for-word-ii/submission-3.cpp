class Node
{
public:
   vector<Node*> links;
   bool flag;
   string word;

   Node() : flag(false)
   {
     links.resize(26,nullptr);
     word = "";
   }

   void insertWord(string &str, Node *node)
   {
      int n = str.size();
      

      for(int i=0; i<n; i++)
      {
          int pos = str[i] - 'a';
          if(!node->links[pos])
          {
            node->links[pos] = new Node();
          }
          node = node->links[pos];
      }
      node->flag = true;
      node->word = str;
   }
};

class Solution {
public:
    bool isValid(int rw, int cl, int n, int m)
    {
        if(rw >= 0 && rw < n && cl >= 0 && cl < m)
          return true;
        return false;
    }
    void dfs(auto &board, Node *node, int rw, int cl, auto &dirRw, auto &dirCl, auto &ans, int n, int m)
    {
        char ch = board[rw][cl];
       

        if(ch == '#' || !node->links[ch-'a'])
          return ;

        board[rw][cl] = '#';
        node = node->links[ch-'a'];

        if(node->flag)
        {
            ans.push_back(node->word);
            node->flag = false;
            //return ;
        }


        for(int i=0; i<4; i++)
        {
            int newRw = rw + dirRw[i], newCl = cl + dirCl[i];

            if(isValid(newRw,newCl,n,m))
            {
                 dfs(board,node, newRw, newCl, dirRw, dirCl, ans, n, m);
            }
        }

        board[rw][cl] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        Node *root = new Node();
        int n = board.size(), m = board[0].size();
        vector<string> ans;
        vector<int> dirRw = {1,0,0,-1};
        vector<int> dirCl = {0,1,-1,0};

        Node *node = root;

        for(int i=0; i<words.size(); i++)
        {
            node->insertWord(words[i],node);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dfs(board,node,i,j,dirRw,dirCl,ans,n,m);
            }
        }
        return ans;
    }
};

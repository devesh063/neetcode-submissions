class Solution {
public:
    bool dfs(vector<vector<int>> &adjLst, int node, int parentNode, vector<bool> &visited)
    {
        visited[node] = true;


        for(int adjNode : adjLst[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjLst,adjNode,node,visited))
                  return true;
            }
            else if(adjNode != parentNode)
            {
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjLst(n, vector<int>());
        vector<bool> visited(n,false);
        int cnt = 0;
        for(auto &it : edges)
        {
            adjLst[it[0]].push_back(it[1]);
            adjLst[it[1]].push_back(it[0]);
        }
      
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                ++cnt;

                if(cnt > 1)
                  return false;
                if(dfs(adjLst,i,-1,visited))
                  return false;
            }
        }
        return true;
    }
};

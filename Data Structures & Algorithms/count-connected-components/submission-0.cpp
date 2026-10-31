class Solution {
public:
    void dfs(auto &adjLst, int node, auto &visited)
    {
        visited[node] = true;

        for(int adjNode : adjLst[node])
        {
            if(!visited[adjNode])
            {
                dfs(adjLst,adjNode,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) 
    {
       vector<vector<int>> adjLst(n,vector<int>());
       vector<bool> visited(n,false);
       int comp = 0;

       for(auto &it : edges)
       {
          adjLst[it[0]].push_back(it[1]); //Un-directed
          adjLst[it[1]].push_back(it[0]);
       }

       for(int i=0; i<n; i++)
       {
          if(!visited[i])
          {
            ++comp;
            dfs(adjLst,i,visited);
          }
       }
       return comp;
    }
};

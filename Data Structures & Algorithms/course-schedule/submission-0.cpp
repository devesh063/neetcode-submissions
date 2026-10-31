class Solution {
public:
    bool dfs(auto &adjLst, int node, auto &visited, auto &pathVisited)
    {
        visited[node] = pathVisited[node] = true;

        for(int adjNode : adjLst[node])
        {
            if(!visited[adjNode])
            {
                 if(dfs(adjLst,adjNode,visited,pathVisited))
                   return true;
            }
            else if(pathVisited[adjNode])
              return true;
        }

        pathVisited[node] = false;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
          //detect cycle in directed graph 
          vector<vector<int>> adjLst(numCourses, vector<int>());

          for(auto &it : prerequisites)
          {
            adjLst[it[0]].push_back(it[1]); //Directed Graph 
          }  

          vector<bool> visited(numCourses,false), pathVisited(numCourses,false);

          for(int i=0; i<numCourses; i++)
          {
            if(!visited[i])
            {
                if(dfs(adjLst,i,visited,pathVisited))
                  return false;
            }
          }
          return true;
    }
};

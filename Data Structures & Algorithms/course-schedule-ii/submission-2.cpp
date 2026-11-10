class Solution {
public:
    bool dfs(vector<vector<int>> &adjLst, int node, vector<bool> &visited, vector<bool> &pathVisited, vector<int> &ans)
    {
        visited[node] = pathVisited[node] = true;
        

        for(int adjNode : adjLst[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjLst,adjNode,visited,pathVisited,ans))
                  return true;
            }
            else if(pathVisited[adjNode])
            {
              //cout << "adjNode :" << adjNode << "\n";
              return true;
            }
        }

        ans.push_back(node);
        pathVisited[node] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
       vector<vector<int>> adjLst(numCourses, vector<int>());

       for(auto &it : prerequisites)
       {
          adjLst[it[1]].push_back(it[0]); //directed graph
       }    

       vector<bool> visited(numCourses,false);
       vector<bool> pathVisited(numCourses, false);
       vector<int> ans;

       for(int i=0; i<numCourses; i++)
       {
          if(!visited[i])
          {
              if(dfs(adjLst,i,visited,pathVisited,ans))
                return {};
          }
       }
       reverse(ans.begin(),ans.end());

       return ans;
    }
};

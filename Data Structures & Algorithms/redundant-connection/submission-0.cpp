class DisJointSet
{
private:
   vector<int> rank, parent;
public:
   DisJointSet(int n)
   {
     rank.resize(n+1,0);
     parent.resize(n+1);
     for(int i=0; i<=n; i++)
     {
        parent[i] =  i;
     }
   }

   int findUparent(int node)
   {
    if(node == parent[node])
      return node;
    return parent[node] = findUparent(parent[node]);
   }

   void unionByRank(int u, int v)
   {
      int ul_u = findUparent(u);
      int ul_v = findUparent(v);

      if(ul_u == ul_v)
        return ;
      
      if(rank[ul_u] < rank[ul_v])
      {
        parent[ul_u] = ul_v;
      }
      else if(rank[ul_v] < rank[ul_u])
      {
        parent[ul_v] = ul_u;
      }
      else
      {
        parent[ul_v] = ul_u;
        rank[ul_v]++;
      }
   }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
       int n = edges.size();
       vector<int> ans(2,0);
       
       DisJointSet ds(n);

       for(auto &it : edges)
       {
          if(ds.findUparent(it[0]) != ds.findUparent(it[1]))
          {
            ds.unionByRank(it[0],it[1]);
          }
          else
          {
            ans[0] = it[0];
            ans[1] = it[1];

            return ans;
          }
       }
      return ans;
    }
};

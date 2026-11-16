class compare
{
public:
   bool operator()(const auto &it1, const auto &it2)
   {
      return (it1.first < it2.first);
   }
};
class DisJointSet
{
private:
   vector<int> size;
   vector<int> parent;
public:
   DisJointSet(int n)
   {
      size.resize(n+1,1);
      parent.resize(n+1);

      for(int i=0; i<=n; i++)
      {
        parent[i] = i;
      }
   }
   int findUparent(int node)
   {
      if(node == parent[node])
        return node;
      return parent[node] = findUparent(parent[node]);
   }
   void unionBySize(int u, int v)
   {
      int ul_u = findUparent(u);
      int ul_v = findUparent(v);

      if(ul_u == ul_v)
        return ;
     
     if(size[ul_u] < size[ul_v])
     {
        parent[ul_u] = ul_v;
        size[ul_v] += size[ul_u];
     }
     else
     {
        parent[ul_v] = ul_u;
        size[ul_u] += size[ul_v];
     }
   }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
       int n = points.size();
       vector<pair<int,pair<int,int>>> adjLst;
       
       for(int i=0; i<n; i++)
       {
          for(int j=i+1; j<n; j++)
          {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                adjLst.push_back({dist,{i,j}});
          }
       }

       sort(adjLst.begin(),adjLst.end(),compare());
       int cst = 0;
       DisJointSet ds(n);

       for(auto &it : adjLst)
       {
          int dist =  it.first, u = it.second.first, v = it.second.second;

          if(ds.findUparent(u) != ds.findUparent(v))
          {
             cst += dist;
             ds.unionBySize(u,v);
          }
       }
       return cst;        
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adjLst(n+1, vector<pair<int,int>>());

        for(auto &it : times)
        {
            int u = it[0], v = it[1], w =  it[2];

            adjLst[u].push_back({v,w}); //Directed Graph
        }

        vector<int> dist(n+1, (int)1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;

        pq.push({0,k});


        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();

            int node = it.second;

            for(auto &adj : adjLst[node])
            {
                int adjNode = adj.first,  wt = adj.second;

                if(dist[adjNode] > dist[node] + wt)
                {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

        int maxTime = 0;

        for(int i=1;i<=n;i++)
        {
            maxTime = max(maxTime,dist[i]);
        }

        return maxTime == (int)1e9 ? -1 : maxTime;
    }
};

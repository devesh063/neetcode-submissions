class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
       int n = nums.size();
       unordered_map<int,int> map;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
       vector<int> ans;

       for(int i=0; i<n; i++)
       {
           map[nums[i]] += 1;  
       }    

        for(auto &it : map)
        {
            int freq = it.second, el = it.first;

            minHeap.push({freq,el});

            if(minHeap.size() > k)
              minHeap.pop();
        }

        while(!minHeap.empty())
        {
             auto it = minHeap.top(); minHeap.pop();
             ans.push_back(it.second);
        }
        return ans;
    }
};

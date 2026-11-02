class Solution {
public:
    void print(auto &vec)
    {
        for(int i=0; i<vec.size(); i++)
        {
           cout<< vec[i][0] << " " << vec[i][1] << "\n";
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {  
       intervals.push_back(newInterval);

       sort(intervals.begin(),intervals.end());
       
       int n = intervals.size();

       vector<vector<int>> ans;  ans.push_back(intervals[0]);
          
       //print(intervals);

       for(int i=1; i<n; i++)
       {
          if(ans[ans.size()-1][1] >= intervals[i][0])
          {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1],intervals[i][1]);
          }
          else
          {
            ans.push_back(intervals[i]);
          }
       }
       return ans;    
    }
};

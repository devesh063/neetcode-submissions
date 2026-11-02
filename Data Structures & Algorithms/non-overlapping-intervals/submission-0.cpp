class compare
{
public:
   bool operator()(const auto &it1, const auto &it2)
   {
      if(it1[0] != it2[0])
      {
        return (it1[0] < it2[0]);
      }
      return (it1[1] < it2[1]);
   }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),compare()); 

        int cnt = 0, prevEnd = intervals[0][1];

        for(int i=1; i<n; i++)
        {
           if(prevEnd > intervals[i][0])
           {
               ++cnt;
               prevEnd = min(prevEnd,intervals[i][1]);
           }
           else
           {
               prevEnd = intervals[i][1];
           }
        }
        return cnt;   
    }
};

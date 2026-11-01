/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class compare
{
public:
  bool operator()(const Interval &it1, const Interval &it2)
  {
      if(it1.start != it2.start)
      {
        return it1.start < it2.start;
      }
      return it1.end < it2.end;
  }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
       int n = intervals.size();

       sort(intervals.begin(),intervals.end(),compare()); 
       priority_queue<int, vector<int>, greater<int>> pq;

       for(auto &it : intervals)
       {
          if(!pq.empty() && pq.top() <= it.start)
          {
             pq.pop();
          }
          pq.push(it.end);

          if(pq.size() > 1)
            return false;
       }
       return true;
    }
};

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
  bool operator()(Interval &it1, Interval &it2)
  {
        if(it1.start != it2.start)
        {
           return (it1.start < it2.start);
        }
        return (it1.end < it2.end);
  }
};

class Solution {
public:
    void print(vector<Interval> &vec)
    {
        for(int i=0; i<vec.size(); i++)
        {
            cout<< vec[i].start  << " " << vec[i].end << "\n";
        }
        cout<< "\n";
    }
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),compare());
        //print(intervals);

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : intervals)
        {
            if(!pq.empty() && pq.top() <= it.start)
            {
                pq.pop();
            }
            pq.push(it.end);
        }
       return pq.size();
    }
};

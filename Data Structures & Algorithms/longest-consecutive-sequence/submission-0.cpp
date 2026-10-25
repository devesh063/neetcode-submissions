class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
       int n = nums.size();
       unordered_set<int> set;
       int ans = 0;

       for(int num : nums)
         set.insert(num);

       for(int num : nums)
       {
          if(set.find(num) != set.end() && set.find(num-1) == set.end())
          {
             int curr = num, cnt = 0;

             while(set.find(curr) != set.end())
             {
                ++curr; ++cnt;
             }
             ans = max(ans,cnt);
          } 
       }
       return ans;    
    }
};

class Solution {
public:
    int findLowerBound(vector<int> &ans, int value)
    {
        int low = 0, high = ans.size() - 1;

        while(low <= high)
        {
            int mid = (high-low)/2 + low;

            if(ans[mid] >= value)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
       //Find Longest Increasing sub sequence via binary search 
       int n = nums.size();  
       vector<int> ans; ans.push_back(nums[0]);

       for(int i=1; i<n; i++)
       {
          if(ans[ans.size()-1] < nums[i])
          {
            ans.push_back(nums[i]);
          }
          else
          {
            int lb = findLowerBound(ans,nums[i]);

            ans[lb] = nums[i];
          }
       }
       return ans.size();
    }
};

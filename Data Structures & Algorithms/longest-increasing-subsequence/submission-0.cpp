class Solution {
public:
    int findLIS(vector<int> &nums, int idx, int n, int prevIdx, vector<vector<int>> &dp)
    {
        if(idx == n)
          return 0;
        
        if(dp[idx][prevIdx+1] != -1)
          return dp[idx][prevIdx+1];

        int notPick = findLIS(nums,idx+1,n,prevIdx,dp);
        int pick = 0;

        if(prevIdx == -1 || nums[idx] > nums[prevIdx])
        {
           pick = 1 + findLIS(nums,idx+1,n,idx,dp);
        }

        return dp[idx][prevIdx+1] = max(notPick,pick);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
      int n = nums.size();
      vector<vector<int>> dp(n,vector<int>(n+1,-1));

      return findLIS(nums,0,n,-1,dp);    
    }
};

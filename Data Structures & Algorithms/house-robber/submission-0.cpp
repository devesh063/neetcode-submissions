class Solution {
public:
    int maxAmountRob(vector<int> &nums, int idx, int n, vector<int> &dp)
    {
        if(idx >= n)  return 0;
        
        if(dp[idx] != -1)
          return dp[idx];

        int notPick = maxAmountRob(nums,idx+1,n,dp);

        int pick = nums[idx] + maxAmountRob(nums,idx+2,n,dp);

        return dp[idx] = max(notPick,pick);
    }
    int rob(vector<int>& nums) 
    {
       int n = nums.size();
       
       vector<int> dp(n,-1);

       return maxAmountRob(nums,0,n,dp);    
    }
};

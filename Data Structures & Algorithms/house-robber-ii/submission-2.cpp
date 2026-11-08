    class Solution {
    public:
        int maxAmountRob(vector<int> &nums, int idx, int n, vector<int> &dp)
        {
            if(idx > n)
            return 0;
            
            if(dp[idx] != -1)
            return dp[idx];

            int notPick = maxAmountRob(nums,idx+1,n,dp);

            int pick = nums[idx] + maxAmountRob(nums,idx+2,n,dp);

            return dp[idx] = max(notPick,pick);
        }
        int rob(vector<int>& nums) 
        {
            int n = nums.size();

            if(n==1)
              return nums[0];
                          
            vector<int> dp1(n,-1);
            vector<int> dp2(n,-1);

            return max(maxAmountRob(nums,0,n-2,dp1),maxAmountRob(nums,1,n-1,dp2));
        }
    };

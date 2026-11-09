class Solution {
public:
    int minJump(vector<int> &nums, int idx, int n, vector<int> &dp)
    {
        if(idx == n-1)
          return 0;
        if(idx >= n)
          return (int)1e9;
        
        if(dp[idx] != -1)
          return dp[idx];

        int minOp = (int)1e9;

        for(int i = 1; i <= nums[idx]; i++)
        {
            minOp = min(minOp, 1 + minJump(nums, idx + i, n, dp));
        }

        return dp[idx] = minOp;
    }
    int jump(vector<int>& nums) 
    {
       int n = nums.size();
       int maxDist = 0;
       vector<int> dp(n,-1);

       return minJump(nums,0,n,dp);    
    }
};

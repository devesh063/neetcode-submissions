class Solution {
public:
    bool findPartition(vector<int> &nums, int idx, int sum, int totalSum, int n, vector<vector<int>> &dp)
    {
        if(2*sum == totalSum) return true;

        if(idx == n || 2 * sum > totalSum)
          return false;
        
        if(dp[idx][sum] != -1)
          return dp[idx][sum];

        //Not pick
        bool flag1 = findPartition(nums,idx+1,sum,totalSum,n,dp);
        //Pick 
        bool flag2 = findPartition(nums,idx+1,sum+nums[idx],totalSum,n,dp);

        return dp[idx][sum] = (flag1 || flag2);
    }
    bool canPartition(vector<int>& nums) 
    {
       int n = nums.size(), totalSum = 0;
       
       for(int i=0; i<n; i++)
       {
          totalSum += nums[i];
       }

       vector<vector<int>> dp(n+1, vector<int>((totalSum/2)+1,-1));

       return findPartition(nums,0,0,totalSum,n,dp);    
    }
};

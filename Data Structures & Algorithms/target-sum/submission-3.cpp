class Solution {
public:
    int findWays(vector<int> &nums, int idx, int sum, int n, vector<vector<int>> &dp)
    {
       if(idx == n)
         return sum == 0 ? 1 : 0;
        
        if(dp[idx][sum] != -1)
          return dp[idx][sum];

        int ways = 0;

        ways = findWays(nums,idx+1,sum,n,dp);

        if(sum >= nums[idx])
          ways += findWays(nums,idx+1,sum-nums[idx],n,dp);
        
        return dp[idx][sum] = ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
       //P - positive group
       //N - Negative group 
       //P - N = target 
       //P + N = totalSum 
       //2P = target + totalSum 
       //P = (target + totalSum)/2
       int n = nums.size();
       int totalSum  = 0;

       for(int i=0; i<n; i++)
         totalSum += nums[i];
        
       
       
       //cout << "totalSum :" << totalSum << " target: "<< target << " sum :" << sum << "\n";

       if(totalSum < abs(target)) return 0;

       if((totalSum + target)%2 != 0)  return 0;
       
       int sum = (totalSum + target)/2;

       vector<vector<int>> dp(n, vector<int>(sum+1, -1));

       return findWays(nums,0,sum,n,dp); 
    }
};

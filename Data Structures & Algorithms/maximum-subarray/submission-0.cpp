class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size(), currSum = (int)-1e9, maxSum = (int)-1e9;

        for(int i=0; i<n; i++)
        {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};

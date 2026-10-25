class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
       int n = nums.size(); 
       int numberOfZero = 0, prod = 1;
       vector<int> ans(n,0);

       for(int i=0; i<n; i++)
       {
          if(nums[i] == 0)
           ++numberOfZero;
          else
            prod *= nums[i];
       }

       if(numberOfZero > 1)
         return ans;
       
       for(int i=0; i<n; i++)
       {
           if(nums[i] != 0 && numberOfZero == 0)
            ans[i] = (prod/nums[i]);
           if(nums[i] == 0)
             ans[i] = prod;
       }
       return ans;
    }
};

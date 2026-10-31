class Solution {
public:
    void generateAllComb(vector<int> &nums, int idx, int target, vector<int> &aux, vector<vector<int>> &ans)
    {
        if(idx < 0)
          return ;
        
        if(target == 0)
        {
            ans.push_back(aux);
            return ;
        }

        generateAllComb(nums,idx-1,target,aux,ans);

        if(target >= nums[idx])
        {
             aux.push_back(nums[idx]);
             generateAllComb(nums,idx,target-nums[idx],aux,ans);
             aux.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> aux;

        generateAllComb(nums,n-1,target,aux,ans);

        return ans;
    }
};

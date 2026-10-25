class Solution {
public:
    int Hp(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low - 1 , j = high + 1;
        do
        {
           do
           {
            i++;
           }while(nums[i] < pivot);

           do
           {
            j--;
           }while(nums[j]  > pivot);

           if(i >= j)
             return j;

           swap(nums[i],nums[j]);
        }while(true);
    }
    void quickSort(vector<int> &nums, int low, int high)
    {
        if(low < high)
        {
            int p = Hp(nums,low,high);
            quickSort(nums,low,p);
            quickSort(nums,p+1,high);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
       int n = nums.size();
       vector<vector<int>> ans;
       quickSort(nums,0,n-1); 

       for(int i=0; i<n-2; i++)
       {
          if(i > 0 && nums[i] == nums[i-1])
            continue;
          int j = i + 1, k = n-1;

          while(j < k)
          {
            if(j > i+1 && nums[j] == nums[j-1])
            {
                j++; continue;
            }
            int sum = nums[i] + nums[j] + nums[k];

            if(sum == 0)
            {
             ans.push_back({nums[i],nums[j],nums[k]});
             j++;
             k--;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
          }
       }
       return ans;   
    }
};

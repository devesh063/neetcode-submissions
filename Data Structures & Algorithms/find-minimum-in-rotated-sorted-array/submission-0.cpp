class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        int n = nums.size(), low = 0, high = n-1;

        while(low < high)
        {
            int mid = (high - low)/2 + low;

            if(nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];    
    }
};

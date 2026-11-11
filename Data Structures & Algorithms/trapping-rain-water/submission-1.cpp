class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        int leftMax = (int)-1e9, rightMax = (int)-1e9;
        
        int low = 0, high = n-1, totalWater = 0;

        while(low < high)
        {
            if(height[low] <= height[high])
            {
                if(leftMax < height[low])
                {
                   leftMax = height[low];
                }
                else
                {
                   totalWater += (leftMax - height[low]);
                }
                //cout << "totalWater :" << totalWater << "\n"; 
                low++;
            }
            else
            {
                if(rightMax < height[high])
                {
                    rightMax = height[high];
                }
                else
                {
                    totalWater += (rightMax - height[high]);
                }
                high--;
            }
        }
        return totalWater;
    }
};

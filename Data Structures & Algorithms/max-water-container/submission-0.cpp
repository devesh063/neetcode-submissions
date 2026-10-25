class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int n = heights.size();
        int low = 0, high = n-1, maxWater = 0;

        while(low < high)
        {
            int width = high - low;

            int minHeight = min(heights[low],heights[high]);

            maxWater = max(maxWater,width * minHeight);

            if(heights[low] <= heights[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return maxWater;    
    }
};

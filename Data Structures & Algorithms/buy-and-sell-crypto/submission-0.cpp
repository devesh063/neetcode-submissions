class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int mini = prices[0], maxProfit = 0;

        for(int i=1; i<n; i++)
        {
            if(mini > prices[i])
            {
                mini = prices[i];
            }
            maxProfit = max(maxProfit,prices[i]-mini);
        }    
        return maxProfit;
    }
};

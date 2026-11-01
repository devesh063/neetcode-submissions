class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
       vector<int> ans;
       int n = matrix.size(), m = matrix[0].size();
       
       int startRw = 0, startCl =  0, endRw = n-1, endCl = m-1;
       cout<< "startRw :" << startRw << "endRw :" << endRw << "\n";

       while(startRw <= endRw && startCl <= endCl)
       {
           for(int idx = startCl; idx <= endCl; idx++)
           {
              ans.push_back(matrix[startRw][idx]);
           }
           ++startRw; //Increase the row

           for(int idx = startRw; idx <= endRw; idx++)
           {
              ans.push_back(matrix[idx][endCl]);
           }
           --endCl; //decrease the column
          
           if(startRw <= endRw)
           {
                for(int idx = endCl; idx >=  startCl; idx--)
                {
                    ans.push_back(matrix[endRw][idx]);
                }
                endRw--; //decrease the row
           }
          
           if(startCl <= endCl)
           {
                for(int idx = endRw; idx >= startRw; idx--)
                {
                    ans.push_back(matrix[idx][startCl]);
                }
                ++startCl; //Increase the column
           }
       }
       return ans;
    }
};

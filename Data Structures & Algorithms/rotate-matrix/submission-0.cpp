class Solution {
public:
    void reverse(vector<int> &temp)
    {
        int low = 0, high = temp.size() - 1;

        while(low < high)
        {
            swap(temp[low],temp[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<vector<int>>& matrix) 
    {
      //1. first find the transpose
      //2. Then reverse the every row
      int n = matrix.size(), m = matrix[0].size();

      for(int i=0; i<n; i++)
      {
         for(int j=i; j<n; j++)
         {
            swap(matrix[i][j],matrix[j][i]);
         }   
      }     
      
      for(int i=0; i<n; i++)
      {
        reverse(matrix[i]);
      }
    }
};

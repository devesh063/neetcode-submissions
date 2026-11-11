class Solution {
public:
    int Lp(vector<int>& nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low - 1;

        for(int j=low; j <high; j++)
        {
            if(nums[j] < pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        i++;

        swap(nums[i],nums[high]);
        return i;
    }
    void quickSort(vector<int>&nums, int low, int high)
    {
        if(low < high)
        {
            int p = Lp(nums,low,high);

            quickSort(nums,low,p-1);
            quickSort(nums,p+1,high);
        }
    }
    void genAllSubSet(vector<int> &nums, int idx, int n, vector<int> &aux, vector<vector<int>> &ans)
    {
        ans.push_back(aux);

        for(int i=idx; i<n; i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;

            aux.push_back(nums[i]);

            genAllSubSet(nums,i+1,n,aux,ans);

            aux.pop_back();
        }        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
       int n = nums.size();
       vector<vector<int>> ans;
       vector<int> aux;
       
       quickSort(nums,0,n-1);

       genAllSubSet(nums,0,n,aux,ans);

       return ans; 
    }
};

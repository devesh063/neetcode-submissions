class Solution {
public:
    void genAllCombSum(vector<int> &candidates, int target, int idx, int n, vector<int> &aux, vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(aux);
            return ;
        }

        for(int i=idx; i<n; i++)
        {
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            aux.push_back(candidates[i]);

            genAllCombSum(candidates,target - candidates[i], i+1, n, aux, ans);

            aux.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> aux;

        int n = candidates.size();

        sort(candidates.begin(),candidates.end());

        genAllCombSum(candidates,target,0,n,aux,ans);

        return ans;     
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
    {
        bool x = false, y = false, z = false;

        for(auto &it : triplets)
        {
            if(it[0] > target[0] || it[1] > target[1] || it[2] > target[2])
              continue;
            
            if(it[0] == target[0]) x = true;
            if(it[1] == target[1]) y = true;
            if(it[2] == target[2]) z = true;
        }

        return (x && y && z);
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;

        for(string str : strs)
        {
            vector<int> freq(26,0);

            for(int i=0; i<str.size(); i++)
            {
                freq[str[i]-'a']++;
            }
            
            string key = "";

            for(int i=0; i<26; i++)
            {
                key += to_string(freq[i]) + "#";
            }

            map[key].push_back(str);
        }

        for(auto &it : map)
        {
            ans.push_back(it.second);
        }    

        return ans;
    }
};

class Solution {
public:
    bool isPossible(string &s, int idx, int n, auto &set, vector<int> &dp)
    {
        if(idx == n)
          return true;
        
        if(dp[idx] != -1)
          return dp[idx];

        string temp = "";

        for(int i = idx; i <n ; i++)
        {
            temp += s[i];

            if(set.find(temp) != set.end() && isPossible(s,i+1,n,set,dp))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
      int n = s.size();

      unordered_set<string> set;

      for(string &temp : wordDict)   
         set.insert(temp);
      
      vector<int> dp(n,-1);

      return isPossible(s,0,n,set,dp);
    }
};

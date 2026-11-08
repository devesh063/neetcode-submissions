class Solution {
  public:
    int countVertex(vector<string> &words, unordered_set<int> &set)
    {
        int n = words.size();
        
        for(int i=0;i<n;i++)
        {
            string temp = words[i];
            
            for(int j=0;j<temp.size();j++)
            {
                char ch = temp[j];
                set.insert(ch);
            }
        }
        return set.size();
    }
    string foreignDictionary(vector<string> &words) 
    {
        // code here
        unordered_set<int> set;
        int V = countVertex(words,set);
        vector<vector<int>> adjLst(26,vector<int>());
        vector<int> indegree(26,0);
        queue<int> q;
        string ans = "";
        
        for(int k=1;k<words.size();k++)
        {
            string word1 = words[k-1];
            string word2 = words[k];
            
            int n = word1.size(), m = word2.size(), i = 0, j = 0;
            
            while(i < n && j < m)
            {
                if(word1[i] != word2[j])
                {
                    adjLst[word1[i]-'a'].push_back(word2[j]-'a');
                    indegree[word2[j]-'a']++;
                    break;
                }
                i++;j++;
            }
            if(j == m && n > m ) return "";
        }
        
        for(char i = 'a'; i <= 'z'; i++)
        {
            if(set.find(i) != set.end() && indegree[i-'a'] == 0)
            {
                q.push(i-'a');
            }
        }
        
        while(!q.empty())
        {
            int node = q.front(); q.pop();
            
            ans += (char)(node+'a');
            
            for(int adjNode : adjLst[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                  q.push(adjNode);
            }
        }
        return (V > ans.size() ? "" : ans);
    }
};
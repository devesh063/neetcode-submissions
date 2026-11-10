class Solution {
public:
     int minSteps(string &word1, string &word2, unordered_set<string> &set)
     {
         queue<pair<int,string>> q;

         q.push({1,word1});
         set.erase(word1);
         
         while(!q.empty())
         {
            auto it = q.front(); q.pop();

            int steps = it.first; string word = it.second;
            
            if(word == word2)
              return steps;

            for(int i=0; i<word.size(); i++)
            {
                char ch = word[i];

                for(char idx = 'a'; idx <= 'z'; idx++)
                {
                    word[i] = idx;

                    if(set.find(word) != set.end())
                    {
                        q.push({steps+1,word});
                        set.erase(word);
                    }
                }
                word[i] = ch;
            }
         } 
         return 0;
     }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> set;

        for(string &str : wordList)
        {
            set.insert(str);
        }       

        return minSteps(beginWord,endWord,set);
    }
};

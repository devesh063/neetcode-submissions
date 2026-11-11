class Solution {
public:
    bool checkFreq(vector<int> &freq)
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i] != 0)
              return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size(), m = s2.size();
        
        if(n > m)
          return false;

        vector<int> freq(26,0);

        for(int i=0; i<n; i++)
        {
            freq[s1[i]-'a']++;
        } 

        for(int i=0; i<n; i++)
        {
            freq[s2[i]-'a']--;
        }   

        if(checkFreq(freq))
          return true;
        
        for(int i=n; i<m; i++)
        {
            freq[s2[i]-'a']--; //decrease the freq

            freq[s2[i-n]-'a']++; //Remove the element 
            
            if(checkFreq(freq))
              return true;
        }
        return false;
    }
};

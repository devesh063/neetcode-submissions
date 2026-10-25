class Solution {
public:
    string minWindow(string s, string t) 
    {
       int m = s.size(), n = t.size();

       if(n > m)
          return "";
          
       vector<int> freq(256,0);
       
       for(int i=0; i<n; i++)
       {
         freq[t[i]]++;
       } 

       int start = 0, end = 0, startIdx = 0, endIdx = (int)1e9, len = 0;

       while(end < m)
       {
          int ch = s[end++]; //Increase the window

          if(freq[ch] > 0)
            len++;
          
          freq[ch]--;

          while(len == n)
          {
             if(end - start < endIdx - startIdx)
             {
                startIdx = start;
                endIdx = end;
             }

             int ch1 = s[start++]; //Decrease the window

             freq[ch1]++;

             if(freq[ch1] > 0)
               len--; 
          }        
       }

       if(endIdx == (int)1e9) return "";

       string str = "";

       for(int i=startIdx; i < endIdx; i++)
       {
          str += s[i];
       }

       return str;
    }
};
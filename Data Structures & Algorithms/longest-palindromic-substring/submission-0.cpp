class Solution {
public:
    void expand(string &s, int left, int right, int &startIdx, int &endIdx)
    {
        int n = s.size();
        
        while(left >= 0 && right < n)
        {
            if(s[left] == s[right])
            {
                if((endIdx - startIdx) < (right-left))
                {
                    startIdx = left;
                    endIdx = right;
                }
            }
            else
            {
                return ;
            }
            left--;
            right++;
        }
        return ;
    }
    string longestPalindrome(string s) 
    {
       int n = s.size();
       int startIdx = 0 , endIdx = 0;
       //Using center expansion method

       for(int i=0; i<n; i++)
       {
          expand(s,i,i,startIdx,endIdx);  //odd length 
          expand(s,i,i+1,startIdx,endIdx); //even length
       }

       string temp = "";

       for(int idx = startIdx; idx <= endIdx; idx++)
       {
          temp += s[idx];
       }    
       return temp;
    }
};

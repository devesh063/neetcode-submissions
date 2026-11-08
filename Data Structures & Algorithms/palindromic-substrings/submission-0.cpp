class Solution {
public:
    int expand(string &str, int left, int right)
    {
        int n = str.size();
        int cnt = 0;

        while(left >= 0 && right < n)
        {
            if(str[left] == str[right])
            {
                ++cnt;
            }
            else
            {
                return cnt;
            }
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) 
    {
        //use center expansion method 
        int n = s.size(),  cnt = 0;

        for(int i=0; i<n; i++)
        {
            cnt += expand(s,i,i); //odd length

            cnt += expand(s,i,i+1); //event length
        }    

        return cnt;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.size(), low = 0, high = 0, maxFreq = 0;
        vector<int> freq(256,0);
        int maxLen = 0;

        while(high < n)
        {
            char ch = s[high++]; //increase the window

            freq[ch]++; 

            maxFreq = max(maxFreq,freq[ch]);

            int changesReq = ((high - low) - maxFreq);

            if(changesReq > k)
            {
                char ch1 = s[low++]; //shrink the window

                freq[ch1]--;

                changesReq = (high - low);
            }
            maxLen = max(maxLen,high-low);
        }
        return maxLen;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        vector<int> freq(256,0);
        int low = 0, high = 0, maxLen = 0;

        while(high < n)
        {
            char ch = s[high++]; //Increase the window

            freq[ch]++;

            while(freq[ch] > 1)
            {
                char oldCh = s[low++]; //shrink the window

                freq[oldCh]--;
            }

            maxLen = max(maxLen,high-low); 
        }
        return maxLen;
    }
};

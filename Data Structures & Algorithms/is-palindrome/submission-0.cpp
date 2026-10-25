class Solution {
public:
    bool isPalindrome(string s1) 
    {
        string s = "";
        for(int i=0; i<s1.size(); i++)
        {
            if((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') \
              || (s1[i] >= '0' && s1[i] <= '9'))
            {
                s += tolower(s1[i]);
            }
        }
        
        cout << s << "\n";
        int n = s.size();

        int low = 0, high = n-1;


        while(low < high)
        {
            if(s[low] != s[high])
              return false;
            low++;
            high--;
        }
        return true;    
    }
};

class Solution {
public:
    bool isPalindrome(string &s)
    {
        int low = 0, high = s.size() - 1;

        while(low < high)
        {
            if(s[low] != s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void genAllPalindromePartition(string &s, vector<vector<string>> &ans, vector<string> &aux, int idx, int n)
    {
        
        if(idx == n)
        {
            ans.push_back(aux);

            return ;
        }

        string temp = "";

        for(int i = idx; i <n; i++)
        {
           temp += s[i];

           if(isPalindrome(temp))
           {
              aux.push_back(temp);

              genAllPalindromePartition(s,ans,aux,i+1,n);

              aux.pop_back();
           }    
        }
    } 
    vector<vector<string>> partition(string s) 
    {
       int n = s.size();
       vector<vector<string>> ans;
       vector<string> aux;

       genAllPalindromePartition(s,ans,aux,0,n);

       return ans;
    }
};

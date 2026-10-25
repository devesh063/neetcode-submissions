class Solution {
public:
    bool isSame(char ch1, char ch2)
    {
        if((ch1 == '(' && ch2 == ')') || (ch1 == '[' && ch2 == ']') || (ch1 == '{' && ch2 == '}'))
         return true;
        
        return false;
    }
    bool isValid(string s) 
    {
        stack<char> st;
        int n = s.size();

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                  return false;
                
                if(!isSame(st.top(),s[i]))
                      return false; 
                st.pop();
            }
        }
        return st.empty();    
    }
};

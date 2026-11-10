#define ll long long
class Solution {
public:
    bool isOperator(string &str)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
          return true;
        return false;
    }
    ll cal(ll el1, ll el2, string &str)
    {
        if(str == "+")  return el1 + el2;
        else if(str == "-")  return el1 - el2;
        else if(str == "*")  return el1 * el2;
        else return (el1/el2);
    }
    int evalRPN(vector<string>& tokens) 
    {
       stack<ll> st;
       int n = tokens.size();

       for(int i=0; i<n; i++)
       {
          if(isOperator(tokens[i]))
          {
              ll el1 = st.top(); st.pop();
              ll el2 = st.top(); st.pop();

              st.push(cal(el2,el1,tokens[i]));
          }
          else
          {
              st.push(stoi(tokens[i]));
          }
       }    

       return (int)st.top();
    }
};

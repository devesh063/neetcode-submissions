#define ll long long
class MinStack {
public:
    stack<ll> st;
    ll mini;
    MinStack() 
    {
        mini = LONG_MAX;
    }
    
    void push(int val) 
    {
        ll lval = (ll)val;
        if(mini == LONG_MAX)
        { 
            st.push(lval);
            mini = lval;
        }
        else
        {
            if(lval >= mini)
            {
                st.push(lval);
            }
            else
            {
                ll encoded = 2 * lval - mini;
                st.push(encoded);
                mini = lval;
            }
        }
    }
    
    void pop() 
    {
       if(st.empty())
       {
         return;
       }

       ll popEl = st.top(); st.pop();

       if(popEl < mini)
       {
          ll decode =  2 * mini - popEl;
          mini = decode;
       } 

       if(st.empty())
       {
          mini = LONG_MAX;
       } 
    }
    
    int top() 
    {
        if(st.empty())
        {
            return -1;
        }

        ll topEl = st.top();

        if(topEl >= mini)  return topEl;

        return mini;    
    }
    
    int getMin() {
        if(st.empty())  return -1;
        return (int)mini;
    }
};

class Solution {
public:
    void genAllParenthesis(int op, int cl, vector<string> &ans, string aux)
    {
        if(op == 0 && cl == 0)
        {
           ans.push_back(aux);
           return ;
        }
        
        //cout << "aux :" << aux << "\n";

        if(op != 0)
        {
            genAllParenthesis(op-1,cl,ans,aux+"(");
        }

        if(op < cl)
        {
            genAllParenthesis(op,cl-1,ans,aux+")");
        }
        
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        int open = n, close = n;

        genAllParenthesis(open,close,ans,"");

        return ans;     
    }
};

class Solution {
public:
    double calPow(double x, int n)
    {
        double res = 1;

        while(n > 0)
        {
            if(n&1)
             res *= x;
            x *= x;

            n = (n>>1);
        }
        return res;
    }
    double myPow(double x, int n) 
    {
       if(n == INT_MIN && x == 1.000)
         return 1;
       if(n == INT_MIN && x < 1.0)
         return 1;
       if(n == INT_MIN && x > 1.0)
         return 0;

       int pow = n;

       if(n < 0)
         n = -n;

       double ans = calPow(x,n);

       if (pow < 0)
         return 1/ans;
       return ans;   
    }
};

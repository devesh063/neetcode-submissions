class Solution {
public:
    int squareOfDigits(int n)
    {
        int sum = 0;
        while(n > 0)
        {
           int digit = n % 10;

           sum += (digit * digit);

           n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) 
    {
       unordered_set<int> set;

       while(n != 1)
       {
           if(set.find(n) != set.end())  return false;

           set.insert(n);
           n = squareOfDigits(n);
       }
       return true;    
    }
};

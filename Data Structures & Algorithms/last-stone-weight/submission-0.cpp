class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
       int n = stones.size();

       priority_queue<int, vector<int>> maxHeap;

       for(int num : stones)
         maxHeap.push(num);

       while(maxHeap.size() > 1)
       {
          int el1 = maxHeap.top(); maxHeap.pop();

          int el2 = maxHeap.top(); maxHeap.pop();

          if(el1-el2 != 0)
            maxHeap.push((el1-el2));
       }    
       return (maxHeap.size() == 0 ? 0 : maxHeap.top());
    }
};

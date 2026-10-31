class MedianFinder {
public:
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        maxHeap.push(num);

        minHeap.push(maxHeap.top()); maxHeap.pop();

        maxHeap.push(minHeap.top()); minHeap.pop();

        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }     
    }
    
    double findMedian() 
    {
        if(maxHeap.size() > minHeap.size())
          return (double)maxHeap.top();

        return (maxHeap.top() + minHeap.top())/2.0;    
    }
};

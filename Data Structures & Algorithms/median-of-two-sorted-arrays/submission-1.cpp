class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
       int n = nums1.size(), m = nums2.size();

       if(n > m)
         return findMedianSortedArrays(nums2,nums1);

       int low = 0, high = n;
       int left = (n+m)/2;

       while(low <= high)
       {
          int mid1 = (high-low)/2 + low;
          int mid2 = left - mid1;

          int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1-1]);
          int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2-1]);
          int r1 = (mid1 == n ? INT_MAX : nums1[mid1]);
          int r2 = (mid2 == m ? INT_MAX : nums2[mid2]);

          if(l1 <= r2 && l2 <= r1)
          {
            //cout << "l1 :" << l1 << " l2 :" << l2 << " r1 :" << r1 << " r2 :" << r2 << "\n";
             if((n+m)%2 != 0)
             {
               return min(r1,r2) * 1.0;
             }
             return (min(r1,r2) + max(l1,l2)) / 2.0;
          } 
          else if(l1 > r2)
          {
            high = mid1 - 1;
          }
          else
          {
            low = mid1 + 1;
          }
       }
       return 0.0;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // bs on the smaller arr
        if(n > m)
            return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0, hi = n;
        while(lo <= hi){
            int px = (lo + hi)/2;
            int py = (n + m + 1)/2 - px;
            
            int L1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int L2 = (py == 0) ? INT_MIN : nums2[py - 1];
            
            int R1 = (px == n) ? INT_MAX : nums1[px];
            int R2 = (py == m) ? INT_MAX : nums2[py];
            
            if(L1 > R2)
                hi = px - 1;
            else if(L2 > R1)
                lo = px + 1;
            else{
                int l = max(L1,L2);
                int r = min(R1,R2);
                
                if((n + m) & 1)
                    return (double) l;
                else
                    return (double)(l + r)/2;
            }
            
        }
        
        return -1;
    }
};
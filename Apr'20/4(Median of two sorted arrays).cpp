class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        
        if(x > y)
            return findMedianSortedArrays(nums2, nums1);
        
        // bs on smaller array1 - x size
        int low = 0;
        int high = x;
        
        while(low <= high){
            int px = (low + high)/2;
            int py = (x + y + 1)/2 - px;
            
            int maxleftX = (px == 0) ? INT_MIN : nums1[px - 1];
            int minrightX = (px == x) ? INT_MAX : nums1[px];
            
            int maxleftY = (py == 0) ? INT_MIN : nums2[py - 1];
            int minrightY = (py == y) ? INT_MAX : nums2[py];
            
            // x: maxleftX - minrightX
            // y: maxleftY - minrightY
            
            if(maxleftX <= minrightY and maxleftY <= minrightX){
                // found
                if((x + y) % 2 == 0){
                    return double( (max(maxleftX, maxleftY) + min(minrightX, minrightY)) / 2.0);
                }else
                    return max(maxleftX, maxleftY);
            }else if(maxleftX > minrightY)
                high = px - 1;
            else
                low = px + 1;                        
        }
        
        return -1;// to satisfy the compiler
    }
};

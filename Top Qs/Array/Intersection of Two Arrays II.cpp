class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        while(i < n and j < m){
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] > nums2[j])
                j++;
            else{
                ans.push_back(nums1[i]);
                i++,j++;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        
        set<int> s;
        for(auto x:nums)
            s.insert(x);
        
        int n = s.size();
        
        if(n==1)
            return nums[0];
        else if(n==2)
            return *max_element(nums.begin(), nums.end());
        
        int max1 = *max_element(nums.begin(), nums.end());
        
        int max2 = INT_MIN; 
        for(auto x:nums){
            if(x > max2 and x!=max1)
                max2 = x;
        }
        
        int max3 = INT_MIN;
        for(auto x:nums){
            if(x>max3 and x!=max2 and x!=max1)
                max3 = x;
        }
        
        return max3;
        
    }
};
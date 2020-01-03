class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            hash[nums[i]] = i + 1;
        }
        
        vector<int> t;
        for(int i = 0; i < n; i++){
            int val = target - nums[i];
            
            if(hash[val] and hash[val]!= i+1 )
            {
                
                t.push_back(i);
                t.push_back(hash[val] - 1);
                return t;
            }
        }
        
        return t;
    }
};
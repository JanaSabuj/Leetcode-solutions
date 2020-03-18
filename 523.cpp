class Solution {
public:
	bool checkSubarraySum(vector<int>& nums, int k) {
		int n = nums.size();

		if (n <= 1)
			return false;
        
		for (int i = 0; i < n-1; i++) {
			if (nums[i] == 0 && nums[i + 1] == 0) return true;
		}

		if(k == 0)
			return false;
  
		map<int, int> mp;

		mp[0] = -1;
		int sum = 0;
        
		for (int i = 0; i < n; i++) {
			sum += nums[i];
            
			if (k != 0) {
				sum = sum % k;
                
                                
				if (mp[sum] != 0 and (i - (mp[sum]) + 1 ) >= 2)
					return true;
				else
					mp[sum] = i + 1;
			}

		}

		return false;
	}
};

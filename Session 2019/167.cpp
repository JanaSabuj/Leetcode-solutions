class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int i=0, j=n-1;
        
        vector<int> ans;
        while(i<=j){
            int sum = numbers[i] + numbers[j];
            if(sum>target)
                j--;
            if(sum<target)
                i++;
            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        
        
        return ans;
        
    }
};
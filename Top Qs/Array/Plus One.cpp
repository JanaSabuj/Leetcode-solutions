class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0, dig = 0, carry = 1;
        int n = digits.size();
        vector<int> ans;
        
        for(int i = n - 1; i >= 0; i--){
            sum = digits[i] + carry;
            carry = sum/10;
            dig = sum % 10;
            ans.push_back(dig);
        }
        
        if(carry)
            ans.push_back(1);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
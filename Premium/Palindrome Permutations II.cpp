//https://www.lintcode.com/problem/palindrome-permutation-ii/description
class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
     vector<char> numss;
     vector<string> global_ans;
     bool isOdd;
     char oddChar;
     
     bool canPerm(string &str) {
        // write your code here
        int n = str.size();
        map<char,int> mp;
        
        for(auto x: str)
            mp[x]++;
        
        int odd = 0;
        for(auto pp: mp){
            if(pp.second & 1){
                odd++;
                isOdd = true;
                oddChar = pp.first;
            }
            if(odd > 1)
                return false;
        }
        
        
        for(auto pp: mp){
            int k = pp.second;
            k/= 2;
            while(k--){
                numss.push_back(pp.first);
            }
        }
        
        return true;
    }
    
    void solve(int idx, vector<int>& used, vector<char>& nums, vector<char>& vec){
        int n = nums.size();
        // base
        if(idx == n){
            string str = "";
            for(int i = 0; i < n; i++){
                str += vec[i];
            }
            
            if(isOdd)
                str += oddChar;
                
            for(int i = n-1; i >= 0; i--){
                str += vec[i];
            }
            global_ans.push_back(str);
            return;
        }
        
        // main
        // _
        for(int i = 0; i < n; i++){
            if(used[i])
                continue;            
            
            if (i > 0 and nums[i-1] == nums[i] and !used[i-1])
                continue;
            // dups
            
                used[i] = true;
                vec.push_back(nums[i]);
                solve(idx + 1, used, nums, vec);
                
                vec.pop_back();
                used[i] = false;
            
        }
    }
    
    vector<string> permuteUnique(vector<char>& nums) {
        // _ _ _  
        // ^
        
        int idx = 0;
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        
        vector<int> used(n, 0);// bool
        vector<char> vec;
        solve(idx, used, nums, vec);
        
        return global_ans;
    }
    
    vector<string> generatePalindromes(string &str) {
        // write your code here
        isOdd = false;
           if(!canPerm(str))
            return {};
        
        //2. generate all unique perms of first half
        for(auto x: numss)
            cout << x << endl;
            
        return permuteUnique(numss);
    }
};

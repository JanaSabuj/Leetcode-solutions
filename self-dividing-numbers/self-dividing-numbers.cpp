class Solution {
public:
    bool selfDiv(int x){
        int num = x;
        
        while(x){
            int dig = x % 10;            
            if(dig == 0 || num % dig) return false;
            x /= 10;
        }
        
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(selfDiv(i))
                ans.push_back(i);
        }
        
        return ans;
    }
};
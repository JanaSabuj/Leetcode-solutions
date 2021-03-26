class Solution {
public:
    bool checkRecord(string str) {
        int a = 0;
        int l = 0;
        
        bool flag = true;
        for(auto x: str){
            
            if(x == 'L'){
                l++;
                if(l >= 3){
                    flag = false;
                    break;
                }
            }else {
                if(x == 'A') { a++; if(a >= 2) {
                    flag = false;
                    break;
                }}
                l = 0;
            }
            
        }
        
        return flag;
    }
};
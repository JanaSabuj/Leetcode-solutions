class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int global = 0;
        for(auto x: S){
            if(x == '('){
                cnt++;
            }else{
                cnt--;
                if(cnt < 0){
                    cnt = 0;
                    global++;// extra opening bracket needed
                }
            }                
        }
        
        if(cnt > 0)
            global += cnt;// no of closing brackets needed
        return global;
    }
};

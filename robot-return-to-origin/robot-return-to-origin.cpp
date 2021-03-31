class Solution {
public:
    bool judgeCircle(string moves) {
        int lr = 0, ud = 0;
        for(auto x: moves){
            switch(x){
                case 'L': lr--;break;
                case 'R': lr++; break;
                case 'U': ud--; break;
                case 'D': ud++; break;
                default: break;
            }
        }
        
        return (lr == 0 and ud == 0);
    }
};
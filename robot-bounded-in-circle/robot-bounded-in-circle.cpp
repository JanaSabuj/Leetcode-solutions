class Solution {
public:
    // N E S W
    // 0 1 2 3
    vector<vector<int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    
    bool isRobotBounded(string instr) {
        int x = 0, y = 0, d = 0;
        for(auto ch: instr){
            switch(ch) {
                case 'G':
                    x += dirs[d][0];
                    y += dirs[d][1];
                    break;
                case 'R':
                    d = (d + 1) % 4;
                    break;
                case 'L':
                    d = (d - 1 + 4) % 4;
                    break;
            }
        }
        
        return (x == 0 and y == 0) || d;
    }
};
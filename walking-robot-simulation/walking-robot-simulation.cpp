class Solution {
public:
    
    bool invalid(int x, int y, set<string>& st){
        return st.count(to_string(x) + " " + to_string(y)) > 0;
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x=0,y=0;
        int j=0;// direction
        int result = 0;// max
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1},{-1,0}};
        
        set<string> st;
        for(auto v: obstacles){
            st.insert(to_string(v[0]) + " " + to_string(v[1]));
        }
        
        for(auto xx: commands){
            if(xx == -1)
                j = (j + 1)%4;// right
            else if(xx == -2)
                j = (j - 1 + 4) % 4;// left
            else{
                while(xx and !invalid(x + dirs[j][0], y + dirs[j][1], st)){
                    x = x + dirs[j][0];
                    y = y + dirs[j][1];
                    xx--;
                }                
                result = max(result, x*x+y*y);
            }
        }
        
        return result;
    }
};

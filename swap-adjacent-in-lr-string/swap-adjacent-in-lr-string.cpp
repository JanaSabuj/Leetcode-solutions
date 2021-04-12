class Solution {
public:
    bool canTransform(string start, string end) {
        
        string s1 = "";
        string s2 = "";
        
        for(auto x: start)
            if(x != 'X')
                s1 += x;
        
        for(auto x: end){
            if(x != 'X')
                s2 += x;
        }
        
        if(s1 != s2)
            return false;
        
        int n = start.size();
        for(int i = 0, j = 0; i < n and j < n; ){
            if(start[i] == 'X')
                i++;
            else if(end[j] == 'X')
                j++;
            else{
                if((start[i] == 'L' and i < j) || (start[i] == 'R' and i > j))
                    return false;
                i++;
                j++;
            }
        }
        
        return true;
    }
};
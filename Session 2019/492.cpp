class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        int l,b;
        int n = area;
        for(int i=1; i<= sqrt(area); i++){
            
            if(n%i == 0){
                if(n/i == i){
                    l = i;
                    b = i;
                }else{
                    b = i;
                    l = n/i;
                }
            }
        }
        
        vector<int> vec;
        vec.push_back(l);
        vec.push_back(b);
        
        return vec;
    }
};
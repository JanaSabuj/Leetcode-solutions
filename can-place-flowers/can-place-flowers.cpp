class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int k) {
        int n = flower.size();
        
        for(int i = 0; i < n; i++){
            if(k == 0)
                return true;
            
            if(flower[i] != 1){
                if((i == 0 || flower[i - 1] != 1) and (i == n-1 || flower[i+1] != 1)){
                    flower[i] = 1;// plant it
                    k--;
                }
            }
        }
        
        return (k == 0);
    }
};

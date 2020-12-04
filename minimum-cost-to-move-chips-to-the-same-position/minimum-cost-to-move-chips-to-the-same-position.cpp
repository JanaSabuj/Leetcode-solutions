class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int odd = 0;
        int even = 0;
        for(auto x: pos){
            if(x & 1)
                odd++;
            else
                even++;
        }
        return min(odd,even);
    }
};

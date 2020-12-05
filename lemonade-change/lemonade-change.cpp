class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(auto x: bills){
            if(x == 5)
                five++;
            else if(x == 10){
                if(five == 0)
                    return false;
                five--;
                ten++;
            }else if(x == 20){
                if((ten == 0 || five == 0) and (five < 3))
                    return false;
                if(ten and five){
                    ten--;
                    five--;
                    twenty++;
                }else{
                    five -= 3;
                }
            }
        }
        
        return true;
    }
};

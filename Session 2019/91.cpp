/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <iostream>
using namespace std;

int numDecodings(string s) {
        int n = s.length();// 2 2 6
        int dp[n + 1];// 1 _ _ _
        dp[0] = 1;// empty
        
        for(int i = 1; i <= n; i++){

            if(i == 1){
            // only 1 letter. So 2 letter case not reqd here.    
                dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];// 0 has no letter allocated to it.
            }
            else{
                
                dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];// individual contribution
                
                int val = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');// last 2 digits

                if(val >= 1 and val <= 26){    
                    if(val>=1 and val<=9){
                        // to cross out cases of 01 to 09 which are invalid 
                        if((s[i-2]) == '0'){
                            // not valid 0 1
                            dp[i] += 0;
                        }else
                            dp[i] += dp[i-2];
                    }
                    else
                        dp[i] += dp[i - 2] ;
                }
                    
            }
            
        }
        
        return dp[n];
    }

int main() {
    freopen("input.txt", "r", stdin);

    string str = "01";
    cout << numDecodings(str) <<endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int myAtoi(string str) {
    auto index = str.find_first_not_of(' ');
    if(index == std::string::npos){
        // all are spaces
        return 0;
    }
    
    bool neg = false;
    long long int ans = 0;
    
    if(str[index] == '-'){
        neg = true;
        index++;
    }else if(str[index] == '+'){
        neg = false;
        index++;
    }
    
    for(int i = index; i < (int)str.length(); i++){
        if(isdigit(str[i])){
            ans = ans * 10 + (str[i] - '0');
            // cout << ans <<endl;
            if(neg and -ans <= INT_MIN) return INT_MIN;
            if(!neg and ans >= INT_MAX) return INT_MAX;
            
        }else{
            break;
        }
    }
    
    return neg ? -ans : ans ;
    
    
}

// To execute C++, please define "int main()"
int main() {
  
    string str = "    -484";
    cout << myAtoi(str) << endl;
    
  return 0;
}

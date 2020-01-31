// GS - What is the angle between the hour and minute hand , given the 
// input time ? 

// e.g - 9 : 30
// Ans: 90 degrees


#include <iostream>
using namespace std;

int GSTime(string time){
    string delim = ":";
    auto start = 0U;
    auto end = time.find(delim);
    
    string hr = time.substr(start, end - start);
    string min = time.substr(end + 1);
    
    // cout << hr <<endl;
    // cout << min <<endl;
    
    // min hand
    // 60 mins -> 360 deg
    // min mins -> 6*min deg 
    
    // hr hand
    // 1 hr -> 30 deg
    // (hr + min/60) hr -> (hr + min/60)* 30 deg
    
    int h = stoi(hr);
    int m = stoi(min);
    
    cout << h <<endl;
    cout << m <<endl;
    
    float ans = ((float)h + ((float)m / 60.0)) * 30.0 - (6.0 * m ) ;
    
    // ans can be abs(ans) or abs(360 - ans);
    return abs(ans);
}

// To execute C++, please define "int main()"
int main() {
  
    string time = "12:30";
    cout << GSTime(time) <<endl;
    
  return 0;
}

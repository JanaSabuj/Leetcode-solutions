#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  
  string str = "Harry-Potter-And-The-Prisoner-Of-Azkaban";
  string delim = "-";
  
  int dl = delim.length();
  
  auto start = 0U;
  auto end = str.find(delim);
  
  vector<string> ans;
  
  while(end != std::string::npos){
    ans.push_back(str.substr(start, end - start));
    start = end + dl;
    end = str.find(delim, start);
  }
                   
  ans.push_back(str.substr(start, end - start));
                   
                   
  for(auto x: ans)
      cout << x <<endl;
                   
                   
  
  return 0;
}

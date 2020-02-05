class Solution {
public:
    string reverseWords(string str) {
    stringstream output(str);
    string word;
    // char delim = ' ';
    
    stack<string> s;
    
    
    while(output >> word){
       s.push(word); 
    }
    
    string ans = "";
    while(!s.empty()){
        string t = s.top();
        s.pop();
        
        
        ans += t;
        if(s.size() != 0)
            ans += " ";
    }
    
    return ans;
}
};

-------------------------------------------------------
// O(1) space

#include <iostream>
using namespace std;

void rever(string& str, int i, int j){
    while(i < j){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
        
        i++;
        j--;
    }
}

void reverseInd(string& str, int n){
    int i = 0, j = 0;
    
    while(i < n){
        // i and j should always be the same
        i = j;
        while(i < n and str[i] == ' ') i++;
        j = i;
        while(j < n and str[j] != ' ') j++;
        rever(str, i, j - 1);
    }    
}

string trimWhite(string& str, int n){
    int i = 0, j = 0;
    
    while(j < n){
        while(j < n and str[j] == ' ') j++;
        while(j < n and str[j] != ' ') str[i++] = str[j++];
        while(j < n and str[j] == ' ') j++;
        if(j < n)// atleast another word is there
            str[i++] = ' ';
    }
    
    return str.substr(0, i);
}



string reverseWords(string str) {
    
    int n = str.length();
    
    //1. reverse the string
    rever(str, 0, n - 1);
    
    //2. reverse individual words
    reverseInd(str, n);
       
    //3. trim the whitespaces
    return trimWhite(str, n);
    
    
    
}

// To execute C++, please define "int main()"
int main() {
  
    string str = "   Hello World  O my dogs  ";
    cout << reverseWords(str) << endl;
    
  return 0;
}


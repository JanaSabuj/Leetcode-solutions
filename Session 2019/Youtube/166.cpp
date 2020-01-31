// 166. Fraction to Recurring Decimal
// Medium

// 661

// 1443

// Add to List

// Share
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
// Accepted
// 107,643
// Submissions
// 521,425

#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(long long int num, long long int den){
    // 4 Base Cases
    
    string output = "";
    
    if(num == 0)
        return "0";
    if(den == 0)
        return "Undefined";// Undefined
    if( (num < 0 and den > 0) or (den < 0 and num > 0))
        output += "-";    
    
     num = abs(num);
    den = abs(den);
    if(num % den == 0){
        output += to_string(num / den);
        return output;
    }
    
   
    long long int q = num / den;
    long long int rem = num % den;
    
    output += to_string(q);
    output += ".";
    
    // begin decimal
    map<long long int,long long int> hash;
    
    while(1){
     
        num = rem * 10;
        //den same
        q = num/den;
        rem = num % den;
        
        // end
        if(rem == 0){
            output += to_string(q);
            return output;
        }
        
        if(hash[rem]){
            output.insert(hash[rem], "(");
            output += to_string(q);
            output += ")";
            break;
        }
        
        output += to_string(q);
        hash[rem] = output.size();
        
    }
    
    return output;
    
}



// To execute C++, please define "int main()"
int main() {
  
    int num = -2147483648;
    int den = 1;
    
    
    cout << fractionToDecimal(num, den) <<endl;
    
  return 0;
}

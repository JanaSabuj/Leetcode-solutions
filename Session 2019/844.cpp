
844. Backspace String Compare
Easy

994

60

Add to List

Share
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
Accepted
96,688
Submissions
205,300

-----------------------------------------------------
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s,t;// 2 stacks for 2 strings
        
        for(auto x: S){
            if( x != '#')
                s.push(x);
            else{
                // #
                if(!s.empty())
                    s.pop();
            }
        }
        
        for(auto x: T){
            if( x != '#')
                t.push(x);
            else{
                // #
                if(!t.empty())
                    t.pop();
            }
        }
        
        while(!s.empty()){
            char c = s.top();
            s.pop();
            
            if(t.empty() or t.top() != c)
                return false;
            
            t.pop();
        }
        
        return t.empty() and s.empty() ;
            
        
    }
};

-----------------------------------------------------------------------
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.length();
        int m = T.length();
        
        int i = n - 1;
        int j = m - 1;
        
        int skipS = 0;
        int skipT = 0;
        
        while(i >=0 or j>= 0){
            
            // get the first valid character of S
            while(i >= 0){
                if(S[i] == '#'){
                    skipS++;
                    i--;
                }else if(skipS > 0){
                    i--;
                    skipS--;
                }else
                    break;
            }
            
            // get the first valid character of T
            while(j >= 0){
                if(T[j] == '#'){
                    skipT++;
                    j--;
                }else if(skipT > 0){
                    j--;
                    skipT--;
                }else
                    break;
            }
            
            // now we have i and j pointing to valid characters
            if(i >= 0 and j>=0 and S[i] != T[j])
                return false;
            
            // if one exists and the other Does not
            if((i >= 0) != (j >= 0))
                return false;
            
            // else it is valid. go ahead
            i--;
            j--;
        }
        
        return true;
        
        
    }
};
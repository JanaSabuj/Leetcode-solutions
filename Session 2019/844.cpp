
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

--------------------------------------------------------------------------
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        for(auto x: S){
            if(x == '#'){
                // #
                if(!s.empty())
                    s.pop();
            }else{
                s.push(x);
            }
        }
        
        string req1 = "";
        while(!s.empty()){
            req1 += s.top();
            s.pop();
        }
        reverse(req1.begin(), req1.end());
        
        stack<char> t;
        for(auto x: T){
            if(x == '#'){
                // #
                if(!t.empty())
                    t.pop();
            }else{
                t.push(x);
            }
        }
        
        string req2 = "";
        while(!t.empty()){
            req2 += t.top();
            t.pop();
        }
        reverse(req2.begin(), req2.end());
        
        return req1 == req2;
        
        
            
    }
};

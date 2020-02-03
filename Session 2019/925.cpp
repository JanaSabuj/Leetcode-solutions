925. Long Pressed Name
Easy

402

51

Add to List

Share
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Note:

name.length <= 1000
typed.length <= 1000
The characters of name and typed are lowercase letters.
 

 
Accepted
29,157
Submissions
65,305

----------------------------------------------------
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.length();
        int m = typed.length();
    
        int i = n - 1;
        int j = m - 1;
        
        
        while(i >= 0 or j >= 0){
            
            int cnt1 = 0;
            int cnt2 = 0;
            
            while(i >= 1 and name[i] == name[i - 1]){
                i--;
                cnt1++;
            }
            
            while(j >= 1 and typed[j] == typed[j - 1]){
                j--;
                cnt2++;
            }
            
            // now both must point to same char
            if(name[i] == typed[j] and cnt2 >= cnt1){
                i--;
                j--;
            }else{
                return false;
            }
            
            
            
        }
        
        return true;
    }
};
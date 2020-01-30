3. Longest Substring Without Repeating Characters
Medium

7567

445

Add to List

Share
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Accepted
1,293,042
Submissions
4,387,718	



---------------------------------------------
class Solution {
public:
  
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r;
        
        
        int ans = 0;
        int n = s.length();
        
        if(n == 0)
            return false;
        
        map<char,int> mp;
        
        int cnt = 0;
        for(r = 0; r < n; r++){
            
            mp[s[r]]++;
                while(mp[s[r]] > 1){
                    mp[s[l]]--;
                    l++;
                }
            
            ans = max(ans, r - l + 1);    
                
        }
        
        return ans;
        
        
    }
};

---------------------------------------------------------
// More Optimised Sliding Window

class Solution {
public:
    int lengthOfLongestSubstring(string S) {
        int l = 0;
        int r;
        
        int ans = 0;
        int n = S.length();
        map<char,int> mp;
        
        for(r = 0; r < n; r++){
            if(mp[S[r]])
                l = max(l, (mp[S[r]] - 1) + 1);// do L
            
            mp[S[r]] = r + 1;// do R
            ans = max(ans, r - l + 1);// updt ans
        }
        
        return ans;
    }
};
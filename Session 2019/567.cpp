567. Permutation in String
Medium

954

51

Add to List

Share
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first strings permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
Accepted
72,983
Submissions
182,738

-----------------------------------------------------------------------

class Solution {
public:
    
    bool isAnagram(int alpha[]){
        for(int i = 0; i < 26; i++)
            if(alpha[i])
                return false;
        return true;
    }
    
    
    bool checkInclusion(string s1, string s2) {
      
        // s2 is BIG
        //s1 is small
        
        int k = s1.length();
        int n = s2.length();
        
        if(n < k)
            return false;
        
        int alpha[26];
        // int kafka[26];
        memset(alpha,0,sizeof(alpha));
        // memset(alpha,0,sizeof(0));
        
        //initial K
        for(int i = 0; i < k; i++){
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;
        }
        
        if(isAnagram(alpha))
            return true;
        
        for(int i = k; i < n; i++){
            alpha[s2[i] - 'a']--;
            alpha[s2[i-k] - 'a']++;
            if(isAnagram(alpha))
                return true;
        }
        
        return false;
    }
};
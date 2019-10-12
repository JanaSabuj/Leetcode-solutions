class Solution {
public:
    int strStr(string haystack, string needle) {
        
        
        int nsz=needle.size();
        if(nsz==0)
            return 0;
        
        int index=haystack.find(needle);
        if(index!=string::npos)
            return index;
        else
            return -1;
        
        
        
        
    }
};
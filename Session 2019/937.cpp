class Solution {
public:
    
    static bool isLess(const string& x, const string& y){
        size_t i = x.find(' ');
        string id1 = x.substr(0,i);
        string word1 = x.substr(i+1);
        
        i = y.find(' ');
        string id2 = y.substr(0,i);
        string word2 = y.substr(i+1);
        
        return (word1==word2)? (id1 < id2) : (word1 < word2);
    }
    
    static bool isLetter(const string& x){
        size_t i = x.find(' ');
        return isalpha(x[i+1]);
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto it = stable_partition(logs.begin(), logs.end(), isLetter);    
        
        sort(logs.begin(), it, isLess);
        
        return logs;
    }
};
class Solution {
    vector<string> vec;
    string temp;
public:
    void helper(string str, int n, int idx){
        cout << temp << endl;
        // base
        if(idx == n){
            vec.push_back(temp);
            return;
        }
        
        if(isalpha(str[idx])){
            temp[idx] = tolower(str[idx]);
            helper(str,n, idx + 1 );
            temp[idx] = str[idx];
            
            temp[idx] = toupper(str[idx]);
            helper(str,n, idx + 1 );
            temp[idx] = str[idx];                        
        }else{
            helper(str, n, idx + 1);
        }
        
        return;
    }
    vector<string> letterCasePermutation(string S) {        
        int n = S.length();
        temp = S;
        helper(S,n,0);
        return vec;
    }
};

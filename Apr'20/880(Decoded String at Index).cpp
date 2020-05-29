class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long int len = 0;
        
        for(int i = 0; i < (int)S.length(); i++){
            if(isalpha(S[i]))
                len++;
            else
                len = len * (S[i] - '0');
        }
        
        if(K > len)
            return "invalid";
        
        K--;
        
        for(int i = (int)S.size() - 1; i >= 0; i--){
            if(isalpha(S[i])){
                if(K == len - 1)
                    return (string)"" + S[i];
                len--;
            }else{
                len = len / (S[i] - '0');
                K = K % len;
            }
        }
        
        return "";
    }
};

class Solution {
public:
    vector<int> LPS(string pattern){
	int n=pattern.length();
	vector<int> lps(n);
	lps[0]=0;
	int j=0,i=1;
	
	while(i<n){
		if(pattern[j]==pattern[i]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else {
			if(j!=0)
				j=lps[j-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}

	return lps;

}
    string longestPrefix(string str) {
        vector<int> lps = LPS(str);
        int n = lps.size();
        int k = lps[n-1];
        return str.substr(0,k);
    }
};

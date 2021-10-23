class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        // [1]
        // [1|2] [2]
        // [1|2|3] [2|3] [3]

        set<int> s;
        for (int i = 0; i < n; ++i){
            if(i == 0) s.insert(arr[i]);
            else {
                s.insert(arr[i]);
                for(int j = i - 1; j >= 0; j--) {
                    if((arr[j] | arr[i]) == arr[j])
                        break;
                    s.insert(arr[i] | arr[j]);
                    arr[j] |= arr[i];
                }
            }
        }

        return s.size();
    }
};
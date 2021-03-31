class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        
        if(n == 1)
            return true;
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                 continue;
            }
            else{
                if(arr[i] >= arr[i-1])
                    continue;
                else{
                    cnt++;
                    if(i - 2 >= 0 and arr[i-2] > arr[i])
                        arr[i] = arr[i-1];
                    else
                        arr[i-1] = arr[i];
                }
            }
        }
        
        return cnt<=1;
    }
};

typedef vector<int> vi;
class Solution {
public:
    bool compLess(const vi& x, const vi& y){
        return ((x[0]*x[0] + x[1]*x[1]) < (y[0]*y[0] + y[1]*y[1]));
    }
    
    int partition(vector<vector<int>>& arr, int l, int r){
        vector<int> pivot = arr[r];
        int i = l - 1;
        
        for(int j = l; j < r; j++){
            if(compLess(arr[j], pivot)){
                i++;
                vi x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
        
        vi x = arr[i + 1];
        arr[i + 1] = arr[r];
        arr[r] = x;
        
        return i + 1;
    }
    
    void qsk(vector<vector<int>>& arr, int l, int r, int k){
        if(l < r){
            int mid = partition(arr, l, r);
            int leftLen = mid - l + 1;
            if(k == leftLen)
                return;
            else if(leftLen > k)
                qsk(arr, l, mid - 1, k);
            else
                qsk(arr, mid + 1, r, k - leftLen);
        }
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       int n = points.size();
       qsk(points, 0, n - 1, K);
       
        vector<vector<int>> ans;
        for(int i = 0; i < K; i++){
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};

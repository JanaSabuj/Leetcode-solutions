class Solution {
public:
    vector<int> minAvailableDuration(vector< vector<int> >& slots1, vector< vector<int> >& slots2, int duration) {
        
        int n = slots1.size();
        int m = slots2.size();
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        
        vector<pair<int,int>> ans;
        
        int i=0,j=0;
        
        while(i < n and j < m){
            
                vector<int> x  = slots1[i];
                vector<int> y = slots2[j];
            
               if(y[1] < x[0]){
                   j++;
                   continue;
               }else if( x[1] < y[0]){
                   i++;
                   continue;
               }
            else{
                
                int a = max (min(x[0],x[1]), min(y[0], y[1]));
                int b = min( max (x[0], x[1]), max(y[0], y[1]));
                
                if(b - a >=duration){
                    // vector<int> tmp = {a,b};
                    ans.push_back({a,a+duration});
                    break;
                }
                
                if(x[1] < y[1])
                     i++;
                else
                    j++;
                
            }
            
            
        }
        
        
        
        
//         for(int i = 0; i< n; i++){
            
//             for(int j = 0; j < m; j++){
                
//                 vector<int> x  = slots1[i];
//                 vector<int> y = slots2[j];
                
//                 int a = max (min(x[0],x[1]), min(y[0], y[1]));
//                 int b = min( max (x[0], x[1]), max(y[0], y[1]));
                
//                 if(b - a >=duration){
//                     // vector<int> tmp = {a,b};
//                     ans.push_back({a,a+duration});
//                 }
                
//             }
            
//         }
        
        int z = ans.size();
        if(z==0)
            return {};
        else{
            
            sort(ans.begin(), ans.end());
            vector<int> tmp;
            tmp.push_back(ans[0].first);
            tmp.push_back(ans[0].second);
            return tmp;
        }
        
        
    }
};
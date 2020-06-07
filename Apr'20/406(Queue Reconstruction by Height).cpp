class Solution {
public:
 
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        if(v1[0] == v2[0])
            return v1[1] < v2[1];
        else
            return v1[0] > v2[0];            
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        
        int n = people.size();
        vector<vector<int>> ans;
        for(auto p: people){
            int idx = p[1];            
            ans.insert(ans.begin() + idx, p);
        }
        
        return ans;
        
    }
};

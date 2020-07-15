class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {        
        vector<set<int>> row(9);
        vector<set<int>> col(9);
        vector<set<int>> box(9);
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if(arr[i][j] == '.')
                    continue;
                
                int x = arr[i][j] - '0' - 1;
                int k = (i / 3) * 3 + j / 3;
                
                if(x > 8 or row[i].find(x) != row[i].end())
                    return false;
                if(col[j].find(x) != col[j].end())
                    return false;
                if(box[k].find(x) != box[k].end())
                    return false;
                
                row[i].insert(x);
                col[j].insert(x);
                box[k].insert(x);
            }
        }
        
        return true;
    }
};

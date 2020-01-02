// Link - https://leetcode.com/discuss/interview-question/373202

/*Given 2 lists a and b. Each element is a pair of integers where the first integer represents the unique id
 and the second integer represents a value. Your task is to find an element from a and an element form b such that the sum of their values is less or equal to target and as close to target as possible. Return a list of ids of selected elements. If no pair is possible, return an empty list.*/


static bool comp(const vector<int>& v1,const vector<int>& v2){
    return (v1[1] < v2[1]);
}

vector<vector<int>> ClosestSum( vector<vector<int>> x,vector<vector<int>> y, int target) {
    sort(x.begin(), x.end(), comp);
    sort(y.begin(), y.end(), comp);
    
    int n = x.size();
    int m = y.size();
    
    int l = 0;
    int r = m - 1;
    
    
    int minDiff = INT_MAX;
    vector<vector<int>> ans;
    
    //2 pointer method
    while(l < n and r >= 0 ){
        int sum = x[l][1] + y[r][1];
        if(sum > target){
            r--;
            continue;
        }
        else{
            // sum <= target
            int dif = target - sum;
            if(dif <= minDiff){
                // better or same ans
                if(dif < minDiff){
                    // better ans
                    minDiff = dif;
                    ans.clear();
                }
          
                int ptr = r ;
                while(ptr>=0 and y[ptr][1] == y[r][1]){
                    // find duplicates
                 vector<int> t; 
                 t.push_back(x[l][0]);
                 t.push_back(y[ptr][0]);
                  
                 ans.push_back(t);
                 ptr--;
                }
            }
            
            l++;
        }
    }
    
    return ans;
}

void print_vector(vector<vector<int>> output){
    cout<<"[";
    for(int i=0;i<output.size();i++){
        cout<<"["<<output[i][0]<<","<<output[i][1]<<"]";
    }
    cout<<"]"<<endl;
}
void tc1()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(2);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(4);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(6);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(2);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 7);
    print_vector(output);
}
void tc2()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(3);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(5);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(7);test1.push_back(temp);
    temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(2);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(3);test2.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(4);test2.push_back(temp);
    temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 10);
    print_vector(output);
}
void tc3()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(8);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(7);test1.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(14);test1.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(5);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(10);test2.push_back(temp);
    temp.clear();temp.push_back(3);temp.push_back(14);test2.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 20);
    print_vector(output);
}
void tc4()
{
    vector<vector<int>> test1;
    vector<int> temp;
    temp.clear();temp.push_back(1);temp.push_back(5);test1.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(5);test1.push_back(temp);
    // temp.clear();temp.push_back(3);temp.push_back(9);test1.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(10);test1.push_back(temp);
    vector<vector<int>> test2;
    temp.clear();temp.push_back(1);temp.push_back(5);test2.push_back(temp);
    temp.clear();temp.push_back(2);temp.push_back(5);test2.push_back(temp);
    // temp.clear();temp.push_back(3);temp.push_back(12);test2.push_back(temp);
    //temp.clear();temp.push_back(4);temp.push_back(5);test2.push_back(temp);
    vector<vector<int>> output= ClosestSum(test1, test2, 20);
    print_vector(output);
}
int main() {
    std::cout << "Hello World!\n";
    tc1();
    tc2();
    tc3();
    tc4();
}

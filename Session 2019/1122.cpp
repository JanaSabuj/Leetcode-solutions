// 1122. Relative Sort Array
// Easy

// 384

// 27

// Add to List

// Share
// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

// Example 1:

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
 

// Constraints:

// arr1.length, arr2.length <= 1000
// 0 <= arr1[i], arr2[i] <= 1000
// Each arr2[i] is distinct.
// Each arr2[i] is in arr1.
// ----------------------------------------------------
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> ha;
        map<int,int> hb;
        map<int,int> hc;
        
        for(auto x: arr2)
            hb[x] = 10;
        
        for(auto x: arr1)
            if(hb[x])
                ha[x]++;
            else
                hc[x]++;
        
        int i = 0;
        for(int j = 0; j < (int)arr2.size(); j++){
            int val = ha[arr2[j]];
            while(val--){
                arr1[i] = arr2[j];
                i++;
            }
        }
        
        for(auto kv : hc){
            int x = kv.first;
            int val = kv.second;
            
            while(val--){
                arr1[i] = x;
                i++;
            }
        }
        
        
        return arr1;
        
    }
};
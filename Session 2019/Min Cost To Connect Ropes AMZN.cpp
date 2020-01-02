// https://leetcode.com/discuss/interview-question/344677
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0

#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    priority_queue<int> pq;
	    while(n--){
	        int x;
	        cin>>x;
	        pq.push(-x);
	    }
	    
	    int ans = 0;
	    
	    while(pq.size() != 1){
	        int x = pq.top();
	        pq.pop();
	        
	        int y = pq.top();
	        pq.pop();
	        
	        pq.push(x+y);
	        ans += (x+y);
	        
	    }
	    
	   // ans += pq.top();
	    cout << -ans <<endl;
	}
	
	
	
	
	return 0;
}
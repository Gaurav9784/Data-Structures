// https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.size();
	    vector<int> a(n,0);
	    stack<int> st;
	    //here we did not push '(' we push index of it and mark in our array
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='('){
	            st.push(i);
	        }
	        else{
	            if(st.empty()){
	                continue;
	            }
	            else{
	                int t=st.top();
	                st.pop();
	                a[i]=1;
	                a[t]=1;
	            }
	        }
	    }
	    //find maxium subarray with one
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(a[i]!=0){
	            a[i]+=a[i-1];
	        }
	        ans=max(a[i],ans);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

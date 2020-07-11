// https://www.youtube.com/watch?v=YxuK6A3SvTs

//https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include <bits/stdc++.h>
using namespace std;
typedef long long int t1;
int main() {
	//code
	t1 t;
	cin>>t;
	while(t--){
	    t1 n;
	    cin>>n;
	    vector<t1> a(n);
	    for(t1 i=0;i<n;i++){
	        cin>>a[i];
	    }
	    t1 msf=INT_MIN,men=0;
	    for(t1 i=0;i<n;i++){
	        men=men+a[i];
	        if(men<a[i]){
	            men=a[i];
	        }
	        if(men>msf){
	            msf=men;
	        }
	    }
	    cout<<msf<<endl;
	}
	return 0;
}

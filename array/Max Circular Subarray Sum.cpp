#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    int meh=0,msf=INT_MIN,start=0;
	    for(int i=0;i<n;i++){
	            meh=meh+a[i];
	            if(meh<a[i]){
	                start=i;
	                meh=a[i];
	            }
	            if(meh>msf){
	                msf=meh;
	            }
	   
	    }
	    int mineh=0,minsf=INT_MAX;
	    //for getting sum of circular array get min sum subarray
	    //and subtract from sum and take max of both
	    for(int i=0;i<n;i++){
	        mineh+=a[i];
	        if(mineh>a[i]){
	            mineh=a[i];
	        }
	        if(mineh<minsf){
	            minsf=mineh;
	        }
	    }
	    int ans=max(msf,sum-minsf);
	    //plz keep in mind if msf is -ve than answer is msf
	    if(msf<0){
	        ans=msf;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

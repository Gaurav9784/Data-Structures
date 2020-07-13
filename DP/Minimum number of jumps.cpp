#include <bits/stdc++.h>
using namespace std;
typedef long long int t1;
t1 fun(vector<t1> &a){
    int n=a.size();
    if(n==1){
        return 0;
    }
    if(a[0]==0){
        return -1;
    }
    t1 jump=1;
    t1 maxrange=a[0];
    t1 steps=a[0];
    for(t1 i=0;i<n;i++){
        if(i==n-1){
            return jump;
        }
        maxrange=max(maxrange,a[i]+i);
        if(steps==0){
            jump++;
            if(maxrange<=i){
                return -1;
            }
            steps=maxrange-i;
        }
        maxrange=max(maxrange,a[i]+i);
        steps--;
    }
    return jump;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    t1 n;
	    cin>>n;
	    vector<t1> a(n);
	    for(t1 i=0;i<n;i++){
	        cin>>a[i];
	    }
	    t1 ans=fun(a);
	    cout<<ans<<endl;
	}
	return 0;
}

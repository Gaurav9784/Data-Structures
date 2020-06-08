#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int ans=1;
	    for(int i=1;i<n;i++){
	        if(a[i]<=a[i-1]){
	            ans=0;
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

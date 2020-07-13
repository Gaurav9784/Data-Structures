#include <bits/stdc++.h>
using namespace std;
int fun(int n,int m,int a[120][120],string s1,string s2){
    if(a[n][m]!=-1){
        return a[n][m];
    }
    if(n==0||m==0){
        a[n][m]=0;
    }
    else{
        if(s1[n-1]==s2[m-1]){
            a[n][m]=1+fun(n-1,m-1,a,s1,s2);
        }
        else{
            a[n][m]=max(fun(n,m-1,a,s1,s2),fun(n-1,m,a,s1,s2));
        }
    }
    return a[n][m];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1>>s2;
	    int a[120][120];
	    for(int i=0;i<120;i++){
	        for(int j=0;j<120;j++){
	            a[i][j]=-1;
	        }
	    }
	    int ans=fun(n,m,a,s1,s2);
	    cout<<ans<<endl;
	}
	return 0;
}

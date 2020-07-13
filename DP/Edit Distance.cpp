#include <bits/stdc++.h>
using namespace std;
int dp(int memo[120][120],int n,int m,string s1,string s2){
    if(memo[n][m]!=-1){
        return memo[n][m];
    }
    if(n==0){
        memo[0][m]=m;
        return memo[0][m];
    }
    else if(m==0){
        memo[n][0]=n;
        return memo[n][0];
    }
    else{
    // !you sholud write n-1,m-1 here not n,m because s1[n] is not valid and it does not throw a error so keep in mind 
        if(s1[n-1]==s2[m-1]){
            memo[n][m]=dp(memo,n-1,m-1,s1,s2);
        }
        else{
            int temp1=dp(memo,n,m-1,s1,s2);
            int temp2=dp(memo,n-1,m,s1,s2);
            int temp3=dp(memo,n-1,m-1,s1,s2);
            memo[n][m]=1+min(min(temp1,temp2),temp3);
        }
        return memo[n][m];
    }
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
	    int memo[120][120];
	    for(int i=0;i<120;i++){
	        for(int j=0;j<120;j++){
	            memo[i][j]=-1;
	        }
	    }
	    int ans=dp(memo,n,m,s1,s2);
	    cout<<ans<<endl;
	}
	return 0;
}

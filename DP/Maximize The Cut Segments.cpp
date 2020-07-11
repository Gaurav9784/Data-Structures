// https://practice.geeksforgeeks.org/problems/cutted-segments/0

#include <bits/stdc++.h>
using namespace std;
int mcs(int n,int a,int b,int c){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(a<=i&&dp[i-a]>=0){
            dp[i]=max(dp[i],1+dp[i-a]);
        }
        if(b<=i&&dp[i-b]>=0){
            dp[i]=max(dp[i],1+dp[i-b]);
        }
        if(c<=i&&dp[i-c]>=0){
            dp[i]=max(dp[i],1+dp[i-c]);
        }
    }
    return dp[n];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,a,b,c;
	    cin>>n>>a>>b>>c;
	    int ans=mcs(n,a,b,c);
	    cout<<ans<<endl;
	}
	return 0;
}

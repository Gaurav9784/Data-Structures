#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll A[n+1];
	    for(ll i=1;i<=n;i++){
	        cin>>A[i];
	    }
	    ll dp[n+1][2];
	    //0=include   1=exclude
	    dp[0][0]=dp[0][1]=0;
	    for(ll i=1;i<=n;i++){
	        // with including of current term we check the min term
	        // to include which can be from the previous include
	        // or can be from the previous exculde
	        dp[i][0]=A[i]+min(dp[i-1][0],dp[i-1][1]);
	        
	        // to exclude the term we will exclude the previouly
	        // included term as we are maintaining the 
	        // optimal substructure property which means 
	        // result of (i-1)th will be best possible
	        dp[i][1]=dp[i-1][0];
	    }
	    
	    // printing the resulting which will be the min of
	    // last term inclusion or exclusion
	    cout<<min(dp[n][0],dp[n][1])<<endl;
	}
	
	return 0;
}
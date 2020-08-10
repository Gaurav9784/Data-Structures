// https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

#include <bits/stdc++.h>
using namespace std;
bool t[52][10002];
vector<int> subsetsum(vector<int> &a,int n,int sum){
    for(int j=0;j<sum+1;j++){
        t[0][j]=false;
    }
    for(int i=0;i<n+1;i++){
        t[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(a[i-1]<=j){
                t[i][j]=t[i-1][j]||t[i-1][j-a[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    vector<int> temp;
    for(int j=0;j<=sum/2;j++){
        if(t[n][j]==true){
            temp.push_back(j);
        }
    }
    return temp;
}
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
	    vector<int> ans=subsetsum(a,n,sum);
	   // for(int i=0;i<ans.size();i++){
	   //     cout<<ans[i]<<" ";
	   // }
	   // cout<<endl;
	    //check min value of sum-2S1
	    int res=INT_MAX;
	    for(int i=0;i<ans.size();i++){
	        if((sum-2*ans[i])<res){
	            res=sum-2*ans[i];
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}

// https://leetcode.com/problems/target-sum/

//in initialisation of first column if zero comes 2^count of zeros till that array size
// (sum+S)%2!=0 because you should take a example like 1 1 1 1 1 1  ans S=3 so it cannot possible
class Solution {
public:
    int t[50][10000];
    int countsubset(vector<int> &a,int n,int temp){
        for(int i=0;i<temp+1;i++){
            t[0][i]=0;
        }
        t[0][0]=1;
        int count=0;
        for(int i=1;i<n+1;i++){
            if(a[i-1]==0){
                count++;
            }
            t[i][0]=pow(2,count);
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<temp+1;j++){
                if(a[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i-1][j-a[i-1]];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][temp];
    }
    int findTargetSumWays(vector<int>& a, int S) {
        int n=a.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum<S){
            return 0;
        }
        if((sum+S)%2!=0){
            return 0;
        }
        int temp=(sum+S)/2;
        int ans=countsubset(a,n,temp);
        return ans;
    }
};

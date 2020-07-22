// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1/?track=ppc-stack&batchId=221

//just find previous smaller(ps) ans next smaller(ns) and do it

long getMaxArea(long long arr[], int n){
    vector<long long int> ps(n),ns(n);
    ps[0]=-1;
    stack<long long int> st;
    st.push(0);
    for(int i=0;i<n;i++){
        while(st.empty()==false&&arr[i]<=arr[st.top()]){
            st.pop();
        }
        ps[i]=(st.empty())?(-1):(st.top());
        st.push(i);
    }
    reverse(arr,arr+n);
    ns[0]=n;
    stack<long long int> st1;
    st1.push(0);
    for(int i=0;i<n;i++){
        while(st1.empty()==false&&arr[i]<=arr[st1.top()]){
            st1.pop();
        }
        ns[i]=(st1.empty())?(n):(n-1-st1.top());
        st1.push(i);
    }
    reverse(arr,arr+n);
    reverse(ns.begin(),ns.end());
    long long int ans=INT_MIN;
    for(int i=0;i<n;i++){
        long long int temp=arr[i];
        temp+=(arr[i]*(i-1-ps[i]));
        temp+=(arr[i]*(ns[i]-i-1));
        ans=max(ans,temp);
    }
    return ans;
}

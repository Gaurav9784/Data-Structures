// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/?track=ppc-stack&batchId=221
// in this we reverse array and find previous greater element by stock span problem method in which we find previous greater element
vector <long long> nextLargerElement(long long arr[], int n){
    reverse(arr,arr+n);
    vector<long long int> ans(n);
    stack<long long int> st;
    st.push(arr[0]);
    ans[0]=-1;
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top()<=arr[i]){
            st.pop();
        }
        ans[i]=(st.empty())?(-1):(st.top());
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

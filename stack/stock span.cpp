// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/?track=ppc-stack&batchId=221

void calculateSpan(int price[], int n, int ans[])
{
   stack<int> st;
   st.push(0);
   ans[0]=1;
   for(int i=1;i<n;i++){
       // we are doing this to find left most greater element
       while(!st.empty()&&price[i]>=price[st.top()]){
           st.pop();
       }
       ans[i]=(st.empty())?(i+1):(i-st.top());
       st.push(i);
   }
}

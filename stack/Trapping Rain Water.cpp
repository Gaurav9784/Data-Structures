//https://leetcode.com/problems/trapping-rain-water/
//create two stack stl and str and have indices of max element from left to right and vice-versa respectively
class Solution {
public:
    int trap(vector<int>& a) {
        int n=a.size();
        stack<int> stl,str;
        str.push(n-1);
        for(int i=n-2;i>=1;i--){
            if(a[i]>a[str.top()]){
                str.push(i);
            }
        }
        stl.push(0);
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(str.top()==i){
                str.pop();
            }
            if(a[i]<=a[stl.top()]&&a[i]<=a[str.top()]){
                int temp=min(a[str.top()],a[stl.top()])-a[i];
                if(temp<0){
                    temp=0;
                }
                ans=ans+temp;
            }
            else if(a[i]>a[stl.top()]){
                stl.push(i);
            }
        }
        return ans;
    }
};

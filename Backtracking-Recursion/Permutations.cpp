https://leetcode.com/problems/permutations/submissions/
// Tech Dose channel video

class Solution {
public:
    void permute(vector<int> &a,int l,int r,vector<vector<int>> &ans){
        if(l==r){
            ans.push_back(a);
        }
        else{
            for(int i=l;i<=r;i++){
                swap(a[i],a[l]);
                permute(a,l+1,r,ans);
                swap(a[i],a[l]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> ans;
        permute(a,0,n-1,ans);
        return ans;
    }
};

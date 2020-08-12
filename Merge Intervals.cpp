//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if(a.size()==0){
            return a;
        }
        vector<pair<int,int>> t;
        for(int i=0;i<a.size();i++){
            t.push_back(make_pair(a[i][0],a[i][1]));
        }
        sort(t.begin(),t.end());
        int start=t[0].first;
        int temp=t[0].second;
        vector<vector<int>> ans;
        for(int i=1;i<t.size();i++){
            if(t[i].first>temp){
                ans.push_back({start,temp});
                start=t[i].first;
                temp=t[i].second;
            }
            else{
                temp=max(temp,t[i].second);
            }
        }
        ans.push_back({start,temp});
        return ans;
    }
};

void dfsutil(vector<int> g[], vector<bool> &v,int t,vector<int> &ans){
    v[t]=true;
    ans.push_back(t);
    for(int i=0;i<g[t].size();i++){
        if(v[g[t][i]]==false){
            dfsutil(g,v,g[t][i],ans);
        }
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    vector<bool> visited(N,false);
    vector<int> ans;
    dfsutil(g,visited,0,ans);
    return ans;

}

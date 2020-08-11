vector <int> bfs(vector<int> g[], int N) {
    queue<int> q;
    q.push(0);
    bool visited[N]={false};
    
    vector<int> ans;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        ans.push_back(t);
        for(int i=0;i<g[t].size();i++){
            if(visited[g[t][i]]==false){
                visited[g[t][i]]=true;
                q.push(g[t][i]);
            }
        }
    }
    return ans;
}

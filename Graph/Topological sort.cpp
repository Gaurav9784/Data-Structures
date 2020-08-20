void ts(vector<int> g[],vector<bool> &visited,int s,stack<int> &st){
    visited[s]=true;
    for(int i=0;i<g[s].size();i++){
        if(visited[g[s][i]]==false){
            ts(g,visited,g[s][i],st);
        }
    }
    st.push(s);
    return;
}
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V,false);
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            ts(adj,visited,i,st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

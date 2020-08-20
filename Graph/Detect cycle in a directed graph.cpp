bool temp(vector<int> g[],int s,vector<bool> &visited,vector<bool> &rstack){
    visited[s]=true;
    rstack[s]=true;
    for(int i=0;i<g[s].size();i++){
        if(visited[g[s][i]]==false){
            if(temp(g,g[s][i],visited,rstack)==true){
                return true;
            }
        }
        else if(rstack[g[s][i]]==true){
            return true;
        }
    }
    rstack[s]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
    vector<bool> rstack(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(temp(adj,i,visited,rstack)==true){
                return true;
            }
        }
    }
    return false;
}

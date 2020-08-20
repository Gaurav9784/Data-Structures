bool temp(vector<int> g[], int s,vector<bool> &visited,int parent){
    visited[s]=true;
    for(int i=0;i<g[s].size();i++){
        if(visited[g[s][i]]==false){
            if(temp(g,g[s][i],visited,s)==true){
                return true;
            }
        }
        else if(g[s][i]!=parent){
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
   vector<bool> visited(V,false);
   for(int i=0;i<V;i++){
       if(visited[i]==false){
           if(temp(g,i,visited,-1)==true){
               return true;
           }
       }
   }
   return false;
   
}

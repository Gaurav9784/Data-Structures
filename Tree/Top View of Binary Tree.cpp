void topView(struct Node *root)
{
    if(root==nullptr){
        return;
    }
    queue<pair<Node *,int>> q;
    q.push(make_pair(root,0));
    map<int,int> m;
    while(!q.empty()){
        pair<Node *,int> p=q.front();
        q.pop();
        if(m.find(p.second)==m.end()){
            m[p.second]=p.first->data;
        }
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second-1));
        }
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second+1));
        }
    }
    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }
}

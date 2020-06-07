void vertical(Node *root,int i){
    map<int,vector<int>> m;
    queue<pair<Node *,int>> q;
    q.push(make_pair(root,i));
    while(!q.empty()){
        pair<Node *,int> p=q.front();
        q.pop();
        Node *temp=p.first;
        m[p.second].push_back(temp->data);
        if(temp->left!=NULL){
            int x=p.second-1;
            q.push(make_pair(temp->left,x));
        }
        if(temp->right!=NULL){
            int y=p.second+1;
            q.push(make_pair(temp->right,y));
        }
    }
    for(auto itr=m.begin();itr!=m.end();itr++){
        for(int i=0;i<itr->second.size();i++){
            cout<<itr->second[i]<<" ";
        }
    }
}
void verticalOrder(Node *root){
    int index=0;
    vector<pair<int,int>> ans;
    vertical(root,index);
}

vector<int> printSiblings(Node *r,vector<int> &i){
    if(r->left&&r->right){
       printSiblings(r->left,i);
       printSiblings(r->right,i);
   }
   else if(r->left){
       i.push_back(r->left->data);
       printSiblings(r->left,i);
   }
   else if(r->right){
       i.push_back(r->right->data);
       printSiblings(r->right,i);
   }
   return i;
}
void printSibling(Node* r)
{
   // Your code here
   if(r==NULL){
       cout<<"-1";
       return;
   }
   vector<int> j;
   vector<int> ans=printSiblings(r,j);
   sort(ans.begin(),ans.end());
   for(int i=0;i<ans.size();i++){
       cout<<ans[i]<<" ";
   }
   if(ans.size()==0){
       cout<<"-1";
   }
}

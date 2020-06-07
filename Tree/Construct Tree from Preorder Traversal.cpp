Node *construct(int n,int pre[],char preLN[],int *i);
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index=0;
    Node *root=NULL;
    root=construct(n,pre,preLN,&index);
    return root;
}
Node *construct(int n,int pre[],char preLN[],int *i){
    if(*i>=n){
        return nullptr;
    }
    else{
        Node *temp=new Node(pre[*i]);
        if(preLN[*i]=='N'){
            *i+=1;
            temp->left=construct(n,pre,preLN,i);
            temp->right=construct(n,pre,preLN,i);
        }
        else{
            *i+=1;
        }
        return temp;
    }
}

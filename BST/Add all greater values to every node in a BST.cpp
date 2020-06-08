Node *great(Node *root,int *count){
    if(root==NULL){
        return nullptr;
    }
    great(root->right,count);
    root->data+=*count;
    *count=root->data;
    great(root->left,count);
    return root;
}
Node* modify(Node *root){
    int count=0;
    root=great(root,&count);
    return root;
}

int sumLeaf(Node* root)
{
    // Code here
    int sum=0;
    if(root==NULL){
        return sum;
    }
    if(root->left==NULL&&root->right==NULL){
        sum+=root->data;
    }
    else{
        int lh=0,rh=0;
        if(root->left){
            lh=sumLeaf(root->left);
        }
        if(root->right){
            rh=sumLeaf(root->right);
        }
        sum=sum+lh+rh;
    }
    return sum;
}

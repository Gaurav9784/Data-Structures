void mirror(Node* node){
    if(node==NULL){
        return;
    }
    if(node->left==NULL&&node->right==NULL){
        return;
    }
    else{
        Node *temp=node->left;
        node->left=node->right;
        node->right=temp;
    }
    mirror(node->left);
    mirror(node->right);
    return;
}

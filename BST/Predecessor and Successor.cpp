void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    Node *temp=root;
    while(temp!=NULL){
        if(temp->key>key){
            suc=temp;
            temp=temp->left;
        }
        else if(temp->key<key){
            pre=temp;
            temp=temp->right;
        }
        else{
            if(temp->left){
                Node *t1=temp->left;
                while(t1){
                    pre=t1;
                    t1=t1->right;
                }
            }
            if(temp->right){
                Node *t2=temp->right;
                while(t2){
                    suc=t2;
                    t2=t2->left;
                }
            }
            break;
        }
    }
}

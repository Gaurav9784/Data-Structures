Node* constructBst(int a[], int n){
    Node *root=nullptr;
    for(int i=0;i<n;i++){
        if(root==nullptr){
            root=new Node(a[i]);
        }
        else{
            int key=a[i];
            Node *prev,*temp=root;
            while(temp!=nullptr){
                if(temp->data>key){
                    prev=temp;
                    temp=temp->left;
                }
                else{
                    prev=temp;
                    temp=temp->right;
                }
            }
            if(key>prev->data){
                prev->right=new Node(a[i]);
            }
            else{
                prev->left=new Node(a[i]);
            }
        }
    }
    return root;
}

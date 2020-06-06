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
bool isSame(Node *a,Node *b){
    
}
int areMirror(Node* a, Node* b) {
    // Your code here
    mirror(a);
    queue<Node *> qa,qb;
    qa.push(a);
    qb.push(b);
    while(!qa.empty()&&!qb.empty()){
        Node *ta=qa.front(),*tb=qb.front();
        qa.pop();
        qb.pop();
        if(ta->data!=tb->data){
            return 0;
        }
        if(ta->left&&tb->left){
            qa.push(ta->left);
            qb.push(tb->left);
        }
        else if(ta->left||tb->left){
            return 0;
        }
        if(ta->right&&tb->right){
            qa.push(ta->right);
            qb.push(tb->right);
        }
        else if(ta->right||tb->right){
            return 0;
        }
    }
    return 1;
}

bool issym(Node *t1,Node *t2){
    if(t1&&t2){
        if(t1->data==t2->data){
            return (issym(t1->left,t2->right)&&issym(t1->right,t2->left));
        }
        else{
            return false;
        }
    }
    else if(!t1&&!t2){
        return true;
    }
    else{
        return false;
    }
}
bool isSymmetric(struct Node* root)
{
	if(root==nullptr){
	    return true;
	}
	Node *t1=root->left,*t2=root->right;
    return issym(t1,t2);
	
}

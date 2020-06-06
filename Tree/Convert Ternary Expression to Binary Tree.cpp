/*Complete the function below
Node is as follows
struct Node{
	char data;
	Node *left,*right;
};
*/
Node *great(string str,int *i){
    Node *root=new Node(str[*i]);
    if(*i==str.size()-1){
        return root;
    }
    *i+=1;
    if(str[*i]=='?'){
        *i+=1;
        root->left=great(str,i);
    }
    else{
        *i+=1;
        return root;
    }
    root->right=great(str,i);
    
    return root;
}
Node *convertExpression(string str,int i){
    Node *root=great(str,&i);
    
    return root;

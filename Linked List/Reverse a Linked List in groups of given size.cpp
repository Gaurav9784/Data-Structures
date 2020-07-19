// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1/?track=ppc-linkedlist&batchId=221
//Recursive solution

struct node *reverse (struct node *head, int k)
{ 
    node *curr=head,*prev=nullptr,*next=nullptr;
    int count=0;
    while(curr!=nullptr&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(curr!=nullptr){
        node *resthead=reverse(curr,k);
        head->next=resthead;
    }
    return prev;
}

*********************************************************************************************************************************************************************************
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

video -link : https://www.youtube.com/watch?v=LtGnA5L6LIk&list=PLqM7alHXFySF7Lap-wi5qlaD8OEBx9RMV&index=18
*********************************************************************************************************************************************************************************

*********************************************************************************************************************************************************************************
Create a stack and push all the id's in the stack.
Run a loop while there are more than 1 element in the stack.
Pop top two element from the stack (represent them as A and B)
Check if A knows B, then A can't be a celebrity and push B in stack. Check if A doesn't know B, then B can't be a celebrity push A in stack
Assign the remaining element in the stack as the celebrity
Run a loop from 0 to n-1 and find the count of persons who knows the celebrity and the number of people whom the celebrity knows. if the count of persons who knows the celebrity is n-1 and the count of people whom the celebrity knows is 0 then return the id of celebrity else return -1.
********************************************************************************************************************************************************************************

*********************************************************************************************************************************************************************************

int knows(int t1,int t2,int M[MAX][MAX]){
    if(M[t1][t2]==1){
        return t2;
    }
    else{
        return t1;
    }
}
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        st.push(i);
    }
    while(st.size()>1){
        int t1=st.top();
        st.pop();
        int t2=st.top();
        st.pop();
        int temp=knows(t1,t2,M);
        st.push(temp);
    }
    int index=st.top();
    st.pop();
    int CKnows=0,OKnows=0;
    for(int i=0;i<n;i++){
        if(i!=index){
            if(M[index][i]){
                CKnows++;
            }
            else if(M[i][index]){
                OKnows++;
            }
        }
    }
    if(CKnows==0&&OKnows==n-1){
        return index;
    }
    else{
        return -1;
    }
}

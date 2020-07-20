// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1/?track=ppc-stack&batchId=221

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    st.push('!');
    int n=s.size();
    string ans;
    for(int i=0;i<n;i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(st.top() !='!'&&st.top() !='('){
                char t=st.top();
                st.pop();
                ans+=t;
            }
            if(st.top() =='('){
                char c=st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != '!' && prec(s[i]) <= prec(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ans += c; 
            } 
            st.push(s[i]);
        }
    }
    while(st.top() != '!') 
    { 
        char c = st.top(); 
        st.pop(); 
        ans += c; 
    }
    return ans;
}

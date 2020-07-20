void SortedStack :: sort()
{
   //Your code here
   stack<int> tempstk;
   while(!s.empty()){
       int temp=s.top();
       s.pop();
       while(!tempstk.empty()&&tempstk.top()>temp){
           s.push(tempstk.top());
           tempstk.pop();
       }
       tempstk.push(temp);
   }
   tempstk.swap(s);
}

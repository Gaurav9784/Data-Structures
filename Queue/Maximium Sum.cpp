// https://practice.geeksforgeeks.org/problems/maximize-the-sum/1/?track=pcc-queue&batchId=221

long maximum_sum(vector<int>v,int k)
{
   // Your code here
   map<int,int> m;
   for(int i=0;i<v.size();i++){
       m[v[i]]++;
   }
   //we make pq of pair<freq,ele> and it is max heap so top() give us larget element
   priority_queue<pair<int,int>> pq;
   for(auto i=m.begin();i!=m.end();i++){
       pq.push(make_pair(i->second,i->first));
   }
   long long ans=0;
   while(k--){
       pair<int,int> p=pq.top();
       pq.pop();
       ans+=p.second;
       p.first--;
       pq.push(p);
   }
   return ans;
}

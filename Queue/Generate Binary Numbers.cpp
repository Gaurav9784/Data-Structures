// https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/?track=pcc-queue&batchId=221

vector<string> generate(ll n)
{
	// Your code here
	vector<string> ans;
	//we push 1 in queue than push 10 and 11 than after popping 10 push 100,101
	queue<string> q;
	q.push("1");
	while(n--){
	    string s1=q.front();
	    q.pop();
	    ans.push_back(s1);
	    string s2=s1;
	    s1+='0';
	    s2+='1';
	    q.push(s1);
	    q.push(s2);
	}
	return ans;
}

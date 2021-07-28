#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	int cnt = N;
	queue<string> q;
	vector<string> res;

	q.push("1");
	while(res.size()<N)
	{
	   string str = q.front();
	   res.push_back(str);
	   q.pop();
	   q.push(str + "0");
	   q.push(str + "1");
	}
	return res;
	
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
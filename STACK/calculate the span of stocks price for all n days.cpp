#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<int>s;
       int arr[n];
       s.push(0);
       arr[0]=1;
       for(int i=0;i<n;i++)
       {
           while(s.empty()==false && price[i]>=price[s.top()])
           {
               s.pop();
           }
       
       arr[i]=s.empty()?i+1:i-s.top();
       s.push(i);
       
    }
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(arr[i]);
    }
    return v;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
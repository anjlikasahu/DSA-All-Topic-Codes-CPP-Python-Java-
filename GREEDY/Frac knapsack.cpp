#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool mycmp(Item a, Item b)
{
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, mycmp);
        double res = 0.0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight<=W)
            {
                res += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                res += arr[i].value*((double)W/arr[i].weight);
                return res;
            }
        }
        return res;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
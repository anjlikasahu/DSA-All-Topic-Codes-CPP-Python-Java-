#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool mycmp(pair<int, int>a, pair<int, int>b)
{
    return(a.second < b.second);
}

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(make_pair(start[i], end[i]));
        }
        sort(arr.begin(), arr.end(), mycmp);
        int prev=0;
        int res=1;
        for(int curr=1; curr<n;curr++)
        {
            if(arr[curr].first > arr[prev].second)
            {
                res++;
                prev=curr;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
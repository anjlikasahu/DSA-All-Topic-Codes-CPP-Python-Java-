#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


bool mycmp(pair<int, int>a, pair<int, int>b)
{
    return a.second < b.second;
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
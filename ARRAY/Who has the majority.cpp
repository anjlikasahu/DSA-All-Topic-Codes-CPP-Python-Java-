// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int majorityWins(int arr[], int n, int x, int y);
// Position this line where user code will be pasted.

int main() {

    int t; // Testcases
    cin >> t; // Input the testcases
    while (t--) // Until all testcases are exhausted
    {
        int n; // Size of array
        cin >> n; // Input the size
        int arr[n]; // Declaring array of size n
        for (int i = 0; i < n;
             i++) // Running a loop to input all elements of arr
            cin >> arr[i];

        int x, y; // declare x and y
        cin >> x >> y; // input x and y
        cout << majorityWins(arr, n, x, y)
             << endl; // calling the function that you complete
    }

    return 0;
}// } Driver Code Ends


// User function Template for C++

// Function to find element with more appearances between two elements in an
// array.
int majorityWins(int arr[], int n, int x, int y) {
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        c1++;
        if(arr[i]==y)
        c2++;
    }
    if(c1>c2)
    return x;
    if(c1<c2)
    return y;
    if(c1==c2)
    {
        if(x>y)
        return y;
        if(x<=y)
        return x;
    }
}
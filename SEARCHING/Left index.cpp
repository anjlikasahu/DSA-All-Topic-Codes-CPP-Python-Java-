#include <iostream>
using namespace std;


 // } Driver Code Ends
// Function to find element in sorted array

int leftIndex(int n, int arr[], int x){
    
    int low = 0, high = n - 1;
    int res = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == x)
            {
                res=mid;
                high=mid-1;
                
            }

        else if(arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return res;
    
    
}




// { Driver Code Starts.

// Driver Code
int main() {
    
    // Testcase input
    int testcases;
    cin >> testcases;
    
    // Looping through all testcases
    while(testcases--){
        int sizeOfArray;
        cin >> sizeOfArray;
        
        int arr[sizeOfArray];
        
        // Array input
        for(int index = 0; index < sizeOfArray; index++){
            cin >> arr[index];
        }
        
        int elemntToSearch;
        cin >> elemntToSearch;
        
        cout << leftIndex(sizeOfArray, arr, elemntToSearch) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
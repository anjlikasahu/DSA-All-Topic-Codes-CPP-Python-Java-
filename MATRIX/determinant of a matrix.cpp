// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

    //Function for finding determinant of matrix.
  class Solution
{   
public:
     void  get_coff( vector<vector<int>> &coff , vector<vector<int>> matrix , int n , int curr )
    {
    //   As the matrix size is (nxn) so he size of the coffactor matrix will be (n-1 x n-1)    
    
         for(int i=1;i<n;i++)
         {
             int k = 0; // k = denoting cols for the coff matrix !
             
             for(int j=0;j<n;j++) 
             {
                    if(j == curr) continue; // if j==curr then we have to ignore that particular column !
                    
                    coff[i-1][k] = matrix[i][j]; // assigning the values correctly !
                    k++; 
             }
         }
    }
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
         if(n==1)
            return matrix[0][0]; // BASE CASE OP !
            
         int sign = 1; // sign variable ! 8D
         
         int sum = 0 ;// the main calculator !!! 
         
         for(int i=0;i<n;i++) // 
         {
             vector<vector<int>> coff(n-1,vector<int>(n-1)); //creating a vector for cofactor matrix !
             
             get_coff(coff , matrix , n , i) ; // getting the cofactors using the function we made above !
             
             sum = sum + (sign * matrix[0][i] * determinantOfMatrix(coff,n-1)) ; // main calculaton !
             
             sign = -sign ; //changing the signs alternatively !
    
         }  
         return sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}  // } Driver Code Ends
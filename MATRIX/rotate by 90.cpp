//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(int n, int m[][n]) 
{
    int t;
    int l,h;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            t=m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = t;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        l=0; h=n-1;
        while(l<h)
        {
            t=m[l][i];
            m[l][i] = m[h][i];
            m[h][i] = t;
            l++;
            h--;
        }
        
    }
} 

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrix[n][n];
	 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		rotateby90(n, matrix);
		for(int i = 0; i < n; i++)
		    for(int j=0; j<n; j++)
			    printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}  // } Driver Code Ends
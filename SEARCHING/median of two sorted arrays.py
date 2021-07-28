#User function Template for python3

class Solution:
    
    #Function to find the median of the two arrays when they get merged.
        
    def findMedianSortedArrays(self,arr1, n1, arr2, n2):
        arr = arr1 + arr2
        arr.sort()
        n= n1+n2
        median = 0
        
        if n % 2 == 0:
            median1 = arr[n//2]
            median2 = arr[n//2 - 1]
            median = (median1 + median2)/2
            median = int(median)
        else:
            median = arr[n//2]
            
        return median
#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        
        n1,n2=list(map(int,(input().split())))
        arr1=list(map(int,(input().split())))
        arr2=list(map(int,(input().split())))
        
        if n1<n2:
            print(Solution().findMedianSortedArrays(arr1,n1, arr2,n2))
        else:
            print(Solution().findMedianSortedArrays(arr2,n2, arr1,n1))
# } Driver Code Ends
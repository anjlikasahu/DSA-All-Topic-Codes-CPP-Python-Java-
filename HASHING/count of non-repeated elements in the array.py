

#User function Template for python3
class Solution:
    
    #Complete this code
    #Function to return the count of non-repeated elements in the array.
    def countNonRepeated(self,arr,n):
        #Your code here
        cnt=0
        a=set(arr)
       
        for i in a:
            if arr.count(i)==1:
                cnt=cnt+1
        return cnt

#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():
    T=int(input())
    while(T>0):
        
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        print(Solution().countNonRepeated(arr,n))
        
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
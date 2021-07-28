
#User function Template for python3
class Solution:
    
    #Complete this function
    #Function to return non-repeated elements in the array.
    def printNonRepeated(self,arr,n):
        #Your code here
        res = []
        for i in arr:
            if arr.count(i)==1:
                res.append(i)
        return res

#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():
    T=int(input())
    while(T>0):
        
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        l = Solution().printNonRepeated(arr,n)
        print(*l)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
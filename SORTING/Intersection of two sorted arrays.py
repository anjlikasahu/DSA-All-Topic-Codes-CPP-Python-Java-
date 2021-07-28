
class Solution:
#Function to return a list containing the intersection of two arrays.

    def printIntersection(self,a, b, n, m):
     
        # code here
        ans = list()
        aa= set(a)
        bb = set(b)
        res = aa.intersection(bb)
        if len(res) ==0:
            return -1
        for i in res:
            ans.append(i)
        ans.sort()
        return ans
            
            

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n,m = map(int,input().strip().split())
        a = list(map(int,input().strip().split()))
        b = list(map(int,input().strip().split()))
        ob=Solution()
        l = ob.printIntersection(a,b,n,m)
        print(*l)
# } Driver Code Ends
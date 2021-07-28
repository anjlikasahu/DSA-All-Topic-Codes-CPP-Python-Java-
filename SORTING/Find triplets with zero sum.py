#User function Template for python3

class Solution:
    #Function to find triplets with zero sum.    
    def findTriplets(self, arr, n):
        #code here
        arr.sort()
        l=0
        s=0
        h=0
        for i in range(0,n-2):
            l=i+1
            h=n-1
            while(l<h):
                s=arr[i]+arr[h]+arr[l]
                if(s==0):
                    return 1
                if(s>0):
                    h= h-1
                if(s<0):
                    l=l+1
        return 0
                

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n=int(input())
        a=list(map(int,input().strip().split()))
        print(Solution().findTriplets(a,n))
# } Driver Code Ends
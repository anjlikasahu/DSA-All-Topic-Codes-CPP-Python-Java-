
#User function Template for python3

class Solution:
    
    #Function to find two repeated elements.
    def twoRepeated(self, arr, N):
        #Your code here
        s=set()
        res=()
        for i in arr:
            if i in s:
                res.append(i)
            else:
                s.add(i)    
        return res[0], res[1];
                                    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math

class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second
    
    
def main():
        T=int(input())
        while(T>0):
            
            N=int(input())

            A=[int(x) for x in input().strip().split()]
            
            obj = Solution()
            ans = obj.twoRepeated(A,N)
            print(ans.first, ans.second)
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends
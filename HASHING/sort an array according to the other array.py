class Solution:
    # A1[] : the input array-1
    # N : size of the array A1[]
    # A2[] : the input array-2
    # M : size of the array A2[]
    
    #Function to sort an array according to the other array.
    def relativeSort (self,A1, N, A2, M):
        # Your Code Here
        m = {}
        for i in A1:
            if i not in m:
                m[i] = 1
            else:
                m[i] += 1
        
        ans = []
        
        for i in A2:
            if i in m:
                while(m[i]):
                    ans.append(i)
                    m[i] -= 1
                
        temp = []
        
        for i in A1:
            if m[i] != 0:
                temp.append(i)
        temp.sort()
        
        for i in temp:
            ans.append(i)
        
        return ans
        
                
            
            
        
#{ Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int (input ())
    while t > 0:
        n, m = list(map(int, input().split()))
        a1 = list(map(int, input().split()))
        a2 = list(map(int, input().split()))
        
        ob=Solution()
        a1 = ob.relativeSort (a1, n, a2, m)
        print (*a1, end = " ")
        
        print ()
        
        t -= 1

# } Driver Code Ends
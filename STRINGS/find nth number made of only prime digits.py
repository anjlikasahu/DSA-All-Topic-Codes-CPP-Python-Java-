#User function Template for python3

class Solution:
    
    #Function to find nth number made of only prime digits.
    def nthprimedigitsnumber(self,n):
        # code here
        arr = {'2', '3', '5', '7'}
        if n == 1:
            return "2"
        num  = 1
        while n!=0 :
            num += 1
            temp = str(num)
            flag = 0
            for i in temp:
                if i not in arr:
                    flag = 1
                    break
            if flag == 0:
                n -= 1
        return temp
                
            
            
            
            
            
            
            
            
        


#{ 
#  Driver Code Starts
#Initial Template for Python 3

import math
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        ob =Solution()
        print(ob.nthprimedigitsnumber(n))
# } Driver Code Ends
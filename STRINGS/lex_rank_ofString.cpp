class Solution{
    
    static int fact(int n){
        
        if(n==1){
            return 1;
        }
        
        return n*fact(n-1);
    }
    
    
    static int countsmaller(String s, int i){
        
        int count = 0;
        
        for(int j=i+1;j<s.length();j++){
            
            if(s.charAt(j)<s.charAt(i)){
                count++;
            }
        }
        
        return count;
    }
    static int rank(String S){
        
        HashSet<Character> set = new HashSet<>(S);
        
        int len = S.length();
        int factorial = fact(len);
        int rank = 1;
        
        //in string acb, factorial becomes 6.
        
        for(int i=0; i<S.length();i++){
            
            //To check for repeated characters.
            if(set.contains(S.charAt(i))){
                return 0;
            }
            
            set.add(S.charAt(i));
            
            factorial = factorial/(len-i);
            
            //count of elements smaller than ith character from i to S.length()
            int count = countsmaller(S,i);
            
            rank = (rank + count*factorial)%1000003;
            
        }
        
        return rank;
    }
}
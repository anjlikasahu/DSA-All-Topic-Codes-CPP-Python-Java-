int solve1(vector<int> &s, int k) {
    int i = 0;
        int j = 0;
        int ans = 0;
        map<int,int> map;
        while(j <= s.size() - 1){
            map[s[j]]++;
            while(map.size() > k){
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
       
int Solution::solve(vector<int> &s, int k) {
        int a = solve1(s,k);
        int b = solve1(s,k-1);
        return a-b;
    }
    
    
    
    
       
    


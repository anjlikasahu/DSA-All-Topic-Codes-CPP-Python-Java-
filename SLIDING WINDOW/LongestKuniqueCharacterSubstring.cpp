int i = 0;
        int j = 0;
        int ans = -1;
        unordered_map<char,int> map;
        while(j <= s.length() - 1){
            map[s[j]]++;
            if(map.size() == k){
                ans = max(ans , j-i+1);
            }
            while(map.size() > k){
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
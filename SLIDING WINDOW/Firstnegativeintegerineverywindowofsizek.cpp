class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    unordered_map<char, int>mp;
	    for(auto it : pat)
	    {
	        mp[it]++;
	    }
	    int cnt=mp.size();
	    int k = pat.size();
	    int i=0;
	    int j=0; int ans =0;
	    while(j<txt.size())
	    {
	        if(mp.find(txt[j]) !=mp.end())
	        {
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	            cnt--;
	        }
	        
	        if(j-i+1<k) j++;
	        else if(j-i+1 == k)
	        {
	            if(cnt ==0)
	            ans++;
	            if(mp.find(txt[i]) != mp.end())
	            {
	            mp[txt[i]]++;
	            if(mp[txt[i]]==1)
	            cnt++;
	            }
	            i++;
	            j++;
	        }
	        
	        
	    }
	    return ans;
	}

};
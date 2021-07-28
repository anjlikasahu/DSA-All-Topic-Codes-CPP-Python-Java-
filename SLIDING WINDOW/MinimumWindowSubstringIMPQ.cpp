class Solution {
public:
    string minWindow(string s, string t) {

         int i=0,j=0,MinL=INT_MAX,start=0;

        unordered_map<char,int> mp;

        //Storing the count of all chars in strinf t in the map
        for(auto it:t)
            mp[it]++;
        int count=mp.size();

        //Checking for the first char in s if it is t
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }

        //Running the algo for all the other chars in s
        while(j<s.length()){

            //If count>0 then we have to increment j and simply check if that char is in t or not. If yes then decrease the cnt of that char in the map.
            if(count>0){
                j++;
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                    count--;
                }
            }

            //When count reaches 0 then, Store the length of the substring from i to j in a variable (MinL here) and store the staring idx as well somehwere.
            else if(count==0){
                // MinL=min(MinL,j-i+1);
                if(MinL>j-i+1){
                    MinL=j-i+1; //Storing the length
                    start=i; //Storing the starting idx.
                }

                //Now we optimise the substring we've gotten by removing the initial chars from the substr i-j. 
                while(count==0){
                    //If the first char is present in t then we inc it's cnt in map.
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){ // If the cnt reaches 1, we naturally have to inc count val also.
                            count++;
                            // MinL=min(MinL,j-i+1);
                             if(MinL>j-i+1){ //Now before incrementing i, we have to store the length of substr from i to j somewhere.
                                MinL=j-i+1; //Storing the length
                                start=i; //Storing the starting idx.
                            } 
                        }
                        //After string length and strating idx, we can now increment i.
                        i++;
                    }
                     //If the first char is not present in t then we just have to inc i.
                    else
                        i++;
                }//This while loop repeats till count == 0.
            }
        }
        //Storing the final answer in a string and returning it.
        string str="";
        if(MinL!=INT_MAX)
            return str.append(s.substr(start,MinL)); //start var has the starting idx of the substr in s and MinL has the length of the substring.
        else
            return str;
    }
        //That's it:)
    
};
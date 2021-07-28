struct Trie{
    int c=0; // represents count of words till this prefix
    Trie *pt[26]={NULL};
};

vector<string> Solution::prefix(vector<string> &v) {
    
    int n=v.size();
    Trie *root=new Trie();
    for(auto s : v){
        Trie* t=root;
        t->c+=1;
        for(auto x : s){
            if(t->pt[x-'a']==NULL){
                t->pt[x-'a']=new Trie();
            }
            t=t->pt[x-'a'];
            t->c+=1;
        }
    }
    vector<string> ans;
    for(auto s : v){
        Trie* t=root;
        string res="";
        for(auto x : s){
            res+=x;
            t=t->pt[x-'a'];
            if(t->c==1) break;
        }
        ans.push_back(res);
    }
    return ans;
}



#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    int i,j;
    queue<int>nq;
    stack<int>st;
    for(i=0;i<k;i++)
    {
        int x=q.front();
        st.push(x);
        q.pop();
    }
    while(!st.empty())
    {
        int x= st.top();
        nq.push(x);
        st.pop();
    }
    while(!q.empty())
    {
        int x=q.front();
        nq.push(x);
        q.pop();
    }
    return nq;
    
}
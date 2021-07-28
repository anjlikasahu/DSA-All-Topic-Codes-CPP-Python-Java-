#include <set>
#include <climits>

using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{

int n;
cin>>n;
int arr[n];

for(int i=0;i<n;i++) cin>>arr[i];

set<int> s;
s.insert(arr[n-1]);

int res=0;
int temp;

for(int i=n-2;i>=0;i--)
{

s.insert(arr[i]);
auto it=s.find(arr[i]);
temp=distance(s.begin(),it);
res=max(res,temp);

}

cout<<res<<endl; 
    
}return 0;
    
}
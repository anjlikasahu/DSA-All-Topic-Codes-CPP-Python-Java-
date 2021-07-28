#include<bits/stdc++.h>
using namespace std;

//N^2 Solution:
int lis1(vector<int> arr)
{
    int n = arr.size();
    vector<int>val(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                val[i]++;
            }
        }
    }
    sort(val.begin(),val.end());
    return val[n-1];

}

//NlogN solution: (Using BS and DP)
int lis2(vector<int>arr)
{
    vector<int>val;
    val.push_back(arr[0]);
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>val.back())
            val.push_back(arr[i]);
        else{
            int idx = lower_bound(val.begin(), val.end(),arr[i]) - val.begin();
            val[idx] = arr[idx];
        }
    }
    return val.size();
}
int main()
{
    vector<int> arr={-1,3,4,5,2,2,2,2};
    cout<<lis1(arr);
    cout<<"\n"<<lis2(arr);
    return 0;
}

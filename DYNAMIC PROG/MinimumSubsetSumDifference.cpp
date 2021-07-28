#include<iostream>
#include<vector>

using namespace std;

bool minsum(vector<int> a, int s, int &maxValue)
{
    vector<int> res;
    vector<vector<bool>>t(a.size()+1, vector<bool>(s+1, false));
    int i,j;
    for(i=0;i<a.size()+1;i++)
        t[i][0]=true;
    for(i=1;i<=a.size();i++)
        for(j=1;j<=s;j++)
            if(a[i-1]<=j)
                t[i][j] = t[i-1][j-a[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
    maxValue=INT32_MIN;
    for(int i=1;i<=s/2;i++){
        if(t[a.size()][i]){
            maxValue=max(maxValue,i);
        }
    }

    return t[a.size()][s];
}

int minSubsetDiff(vector<int>A){
    int range=0;
    for(int i=0;i<A.size();i++){
        range+=A[i];
    }
    int Maxvalue;
    minsum(A,range,Maxvalue);
    return range-2*Maxvalue;
}

int main()
{

    vector<int>a = {1,6,11,5};
    cout<<minSubsetDiff(a);

}

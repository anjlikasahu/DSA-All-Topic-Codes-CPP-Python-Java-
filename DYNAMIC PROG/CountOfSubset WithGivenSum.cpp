#include<iostream>
#include<vector>

using namespace std;

int countsubs(vector<int> a, int sum)
{
    int i, j;
    int n=a.size();
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

    for(i=0;i<=n;i++)
        t[i][0] =1;

    for(i=1;i<=n;i++)
        for(j=1;j<=sum;j++)
            if(a[i-1]<=j)
                t[i][j] = t[i-1][j] + t[i-1][j-a[i-1]];
            else
                t[i][j] = t[i-1][j];

    return t[n][sum];
}

int main()
{
    cout<<countsubs({2,3,5,6,8,10},10); //op 3 {10},{2,8},{2,3,5}

}



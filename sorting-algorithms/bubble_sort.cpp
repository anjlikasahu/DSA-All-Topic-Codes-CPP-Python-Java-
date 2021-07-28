#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

void bubble_sort(vector<int>&A)
{
    for(int i=0;i<A.size()-1;i++)
    {
        for(int j=0;j<A.size()-i-1;j++)
        {
            if(A[j]>A[j+1])
                swap(A[j],A[j+1]);
        }
    }
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    bubble_sort(A);
    print(A);
}
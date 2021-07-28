#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print(vector<int>A)
{
    for(int i=0;i<A.size();i++)
        cout<<A[i]<<"\t";
}

void selection_sort(vector<int>&A)
{
    for(int i=0;i<A.size()-1;i++)
    {
        int min=i;
        for(int j=i+1;j<A.size()-1;j++)
        {
            if(A[j]<A[min])
                min=j;
        }

        if(i!=min)
            swap(A[i],A[min]);
    }
    
}

int main()
{
    vector<int>A={2,5,3,1,6,4,7};
    selection_sort(A);
    print(A);
}